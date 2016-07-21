#include "StringTokenizer.h"
#include <fstream>

using std::ifstream;
//
// Created by Sebastían on 21/07/2016.
//
class FileReader {

private:

    /**
     * Represents the reader
     */
    ifstream * reader;

public:

    /**
     * Constructs a file reader
     */
    FileReader(string file) {
        reader = new ifstream(file);
    }

    /**
     * Consumes the next line if possible
     */
    string consumeLine();
};

