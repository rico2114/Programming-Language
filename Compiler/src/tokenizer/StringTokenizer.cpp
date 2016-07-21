//
// Created by Sebastían on 21/07/2016.
//

#include "StringTokenizer.h"
#include <iostream>
using std::cout;
using std::endl;

bool StringTokenizer::contains(string supply) {
    return localString.find(supply) != string::npos;
}

vector<string> StringTokenizer::tokenize(char delimiter) {
    return tokenize(localString, delimiter);
}

vector<string> StringTokenizer::tokenize(string text, char delimiter) {
    vector<string> list;
    int size = text.size();
    int queue = -1;
    for (int i = 0; i < size; i ++) {
        if (text[i] != delimiter && queue == -1) {
            queue = i;
        } else if (text[i]  == delimiter && queue != -1) {
            list.push_back(text.substr(queue, i - queue));
            queue = -1;
        }
        if (i == size - 1 && queue != -1) {
            list.push_back(text.substr(queue, size - queue));
        }
    }
    return list;
}

string StringTokenizer::deleteAll(string text, char toDelete) {
    int size = text.size();
    char array [size];
    int arrayOffset = 0;
    for (int i = 0; i < size; i ++) {
        if (text[i] != toDelete) {
            array[arrayOffset ++] = text[i];
        }
    }
    array[arrayOffset] = '\0';
    return string(array);
}

string StringTokenizer::deleteAll(char toDelete) {
    return deleteAll(localString, toDelete);
}

vector<string> StringTokenizer::getTextBetween(string text, char left, char right) {
    vector<string> result;
    int size = text.size();
    int queue = -1;
    int offset = 1; // for deleting the char left and char right
    for (int i = 0; i < size; i++) {
        if (text[i] == left && queue == -1) {
            queue = i + offset;
        } else if (text[i] == right && queue != -1) {
            result.push_back(text.substr(queue, i - queue));
            queue = -1;
        }
    }
    return result;
}

vector<string> StringTokenizer::getTextBetween(char left, char right) {
    return StringTokenizer::getTextBetween(localString, left, right);
}
