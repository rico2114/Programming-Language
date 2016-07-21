//
// Created by Sebastían on 21/07/2016.
//

#ifndef COMPILER_INSTRUCTION_H
#define COMPILER_INSTRUCTION_H

#include "ActionOpcode.cpp"
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::ostringstream;

/**
 * Represents an instruction useful for the compiler
 */
class Instruction {

private:

    /**
     * Represents the action opcode
     */
    ActionOpcode::ActionOpcodeEnum opcode;

    /**
     * Represents a list of the parameters
     */
    vector<string> parameters;

public:

    /**
     * Constructs an instruction
     */
    Instruction(ActionOpcode::ActionOpcodeEnum actionOpcode) {
        opcode = actionOpcode;
    }

    /**
     * Adds a parameter to the instruction set
     */
    void addParameter(string parameter) {
        parameters.push_back(parameter.c_str());
    }

    /**
     * Generates the output instruction
     */
    string generateCompiledText() {
        ostringstream stringStream;
        stringStream << opcode << ": ";
        for (string parameter : parameters) {
            stringStream << parameter << " ";
        }
        return stringStream.str();
    }
};

#endif //COMPILER_INSTRUCTION_H
