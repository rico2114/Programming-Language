#include "FileReader.h"

//
// Created by Sebastían on 21/07/2016.
//

string FileReader::consumeLine() {
    const string EMPTY = "EMPTY";
    string line;
    if (std::getline(*reader, line))
        return line;
    else
        return EMPTY;
}
