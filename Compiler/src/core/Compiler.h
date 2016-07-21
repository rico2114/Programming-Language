//
// Created by Sebastían on 21/07/2016.
//

#ifndef COMPILER_COMPILER_H
#define COMPILER_COMPILER_H

#include <string>
#include "../output/Instruction.h"
#include "../tokenizer/StringTokenizer.h"

using std::string;

/**
 * Represents the compiler utility, compiles the source files into the interpreter readable code
 */
class Compiler {

private:

    /**
     * Unused right now
     * Represents a reference for the system to look for source files
     */
    string root;

    /**
     * Represents a list of instructions used for the interpreter
     */
    vector<Instruction> instructions;

public:
    /**
     * Compiles all the root file
     */
    void compileAll();

    /**
     * Compiles a certain file
     */
    void compile(string file);

    /**
     * Registers an instruction into the instructions vector
     */
    void registerInstruction(Instruction instruction);

    /**
     * Registers a function definition
     */
    void registerFunctionDefinition(StringTokenizer tokenizer);

    /**
     * Registers a definition aka assignment
     */
    void registerDefinition(StringTokenizer tokenizer, bool hasChaining);

    /**
     * Registers a function call
     */
    void registerFunctionCall(StringTokenizer tokenizer, bool inAssignment);

    /**
     * Saves all the generated instructions
     */
    void saveAll();
};

#endif //COMPILER_COMPILER_H
