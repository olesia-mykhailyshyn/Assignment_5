#ifndef TOKENIZATION_H
#define TOKENIZATION_H

#include <string>
#include <vector>

using namespace std;

class Tokenization {
public:
    static vector<string> tokenizeExpression(const string& expression);
};

#endif