//
// Created by Sebastían on 21/07/2016.
//

#ifndef COMPILER_STRINGTOKENIZER_H
#define COMPILER_STRINGTOKENIZER_H

#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * Represents a string tokenizer utilized by the compiler to tokenize the language files
 */
class StringTokenizer {

private:
    /**
     * Represents the local constructed string
     */
    string localString;

public:
    /**
     * Constructs an string tokenizer based on a string
     */
    StringTokenizer(string value) {
        localString = value;
    }

    /**
     * Checks if whether or not the string supplied is contained in the local string
     */
    bool contains(string supply);

    /**
     * Tokenizes the local string based on a delimiter
     */
    vector<string> tokenize(char delimiter);

    /**
     * Tokenizes a string based on a delimiter
     */
    vector<string> tokenize(string text, char delimiter);

    /**
     * Attempts to delete all the chars found
     */
    string deleteAll(char toDelete);

    /**
     * Attempts to delete all the chars found in the specific text
     */
    string deleteAll(string text, char toDelete);

    /**
     * Creates a vector of the text between two specific chars left and right
     * make sure that you supply only the smallest possible piece of string
     */
    vector<string> getTextBetween(string text, char left, char right);

    /**
    * Creates a vector of the text between two specific chars left and right
    */
    vector<string> getTextBetween(char left, char right);

};
#endif //COMPILER_STRINGTOKENIZER_H
