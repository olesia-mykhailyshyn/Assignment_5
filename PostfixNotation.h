#ifndef POSTFIXNOTATION_H
#define POSTFIXNOTATION_H

#include <vector>
#include <string>

using namespace std;

class PostfixNotation {
public:
    static vector<string> notation(const vector<string>& tokens);
};

#endif