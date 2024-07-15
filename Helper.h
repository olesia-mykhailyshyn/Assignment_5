#ifndef HELPER_H
#define HELPER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Helper {
public:
    static string input() ;
    static void output(const vector<string>& outputNotation) ;
    static string processDigitExpression(const string& expression, size_t& i, vector<string>& updatedExpression, bool isNumber) ;
    static bool elementOperator(const string& element) ;
    static int getPrecedence(const string& element) ;
    static const map<string, int> MyDictionary;
};

#endif