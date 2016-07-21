//
// Created by Sebastían on 21/07/2016.
//
/**
 * Represents a set of action codes useful for the interpreter
 */
class ActionOpcode {

public:

    /**
     * Represents the action opcode values stored as enums
     */
    enum ActionOpcodeEnum : int {
        /**
         * Represents the return opcode
         */
        RETURN = 2,

        /**
         * Represents the continue loop opcode
         */
        CONTINUE_LOOP = 4,

        /**
         * Represents the break opcode
         */
        BREAK = 8,

        /**
         * Represent the assign value opcode
         */
        ASSIGN_VALUE = 16,

        /**
         * Represents the condition check opcode
         */
        CONDITION_CHECK = 32,

        /**
         * Represents the function call opcode
         */
        FUNCTION_CALL = 64,

        /**
         * Represents a function
         */
        FUNCTION = 128,
    };

};
