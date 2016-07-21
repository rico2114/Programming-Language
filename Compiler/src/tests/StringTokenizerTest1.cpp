//
// Created by Sebastían on 21/07/2016.
//

#include<string>
#include "../tokenizer/StringTokenizer.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class StringTokenizerTest1 {

public:
    void test() {
        string text = "Hola soy nuevo";
        StringTokenizer tokenizer(text);
        cout << tokenizer.contains("nuevo") << endl; // 1
        cout << tokenizer.contains("Nuevo") << endl; // 0
        cout << tokenizer.contains("nuEvO") << endl; // 0
    }

    void test2() {
        string text = "PEDRO                            O                       PIKA PI              EDRAS";
        StringTokenizer tokenizer(text);
        vector<string> list = tokenizer.tokenize(' ');
        for (string s : list) {
            cout << s << endl;
        }
    }

    void test3() {
        string text = "function(vaca, pedro, juan)";
        StringTokenizer tokenizer(text);
        vector<string> list = tokenizer.getTextBetween('(', ')');
        for (string s : list) {
            cout << s << endl;
        }
    }

    void test4() {
        string text = "@soy ju@an el m@as j@o@ven";
        StringTokenizer tokenizer(text);
        string result = tokenizer.deleteAll('@');
        cout << result << endl;
    }
};
