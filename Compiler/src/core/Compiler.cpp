//
// Created by Sebastían on 21/07/2016.
//
#include <string>
#include "Compiler.h"
#include "../tokenizer/FileReader.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

void Compiler::compile(string file) {
    const string SOURCE_EXTENSION = ".code";
    const string EMPTY = "EMPTY";

    if (!file.find(SOURCE_EXTENSION))
        return;

    FileReader reader(file);
    string line;
    do {
        line = reader.consumeLine();
        StringTokenizer tokenizer(line);

        if (tokenizer.contains("function")) {
            registerFunctionDefinition(tokenizer);
        } else if (tokenizer.contains(".")) {
            if (tokenizer.contains("=")) {
                registerDefinition(tokenizer, true);
            } else {
                registerFunctionCall(tokenizer, false);
            }
        } else if (tokenizer.contains("=")) {
            registerDefinition(tokenizer, false);
        }

    } while (line != EMPTY);

    saveAll();
}

void Compiler::registerFunctionDefinition(StringTokenizer tokenizer) {
    vector<string> generatedSpaceList = tokenizer.tokenize(' ');
    string functionName = generatedSpaceList.at(1);

    Instruction instruction(ActionOpcode::ActionOpcodeEnum::FUNCTION);
    functionName = tokenizer.deleteAll(functionName, '(');
    functionName = tokenizer.deleteAll(functionName, ')');
    instruction.addParameter(functionName);

    registerInstruction(instruction);
}

void Compiler::registerFunctionCall(StringTokenizer tokenizer, bool inAssignment) {
    const string EMPTY = "EMPTY";
    vector<string> generatedDotList = tokenizer.tokenize('.');
    string functionType = generatedDotList[0];
    string benefitedVariableName = EMPTY;

    if (inAssignment) {
        vector<string> generatedSpaceList = tokenizer.tokenize(' ');
        functionType = generatedSpaceList[0];
        benefitedVariableName = generatedSpaceList[1];
    }

    vector<string> chainingList = tokenizer.getTextBetween('.', ')');
    for (string chain : chainingList) {
        vector<string> data = tokenizer.tokenize(chain, '(');
        Instruction instruction(ActionOpcode::ActionOpcodeEnum::FUNCTION_CALL);

        string functionName = data[0];
        string parameterValue = data[1];
        instruction.addParameter(functionType);
        instruction.addParameter(functionName);
        instruction.addParameter(benefitedVariableName);
        instruction.addParameter(parameterValue);

        registerInstruction(instruction);
    }
}

void Compiler::registerDefinition(StringTokenizer tokenizer, bool hasChaining) {
    vector<string> generatedSpaceList = tokenizer.tokenize(' ');

    Instruction instruction(ActionOpcode::ActionOpcodeEnum::ASSIGN_VALUE);

    string type = generatedSpaceList[0];
    string name = generatedSpaceList[1];
    string assignment = tokenizer.deleteAll(generatedSpaceList[3], ';');
    if (hasChaining) {
        assignment = tokenizer.tokenize(assignment, '.')[0];
    }
    instruction.addParameter(type);
    instruction.addParameter(name);
    instruction.addParameter(assignment);

    registerInstruction(instruction);

    if (hasChaining) {
        registerFunctionCall(tokenizer, true);
    }
}

void Compiler::registerInstruction(Instruction instruction) {
    instructions.push_back(instruction);
}

void Compiler::saveAll() {
    for (int i = 0; i < instructions.size(); i ++) {
        cout << instructions[i].generateCompiledText() << endl;
    }
}

