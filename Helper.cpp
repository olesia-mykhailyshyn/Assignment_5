#include "Helper.h"
#include <iostream>
#include <cctype>
#include <unordered_map>

using namespace std;

const map<string, int> Helper::MyDictionary = {
        {"+", 1},
        {"-", 1},
        {"*", 2},
        {"/", 2},
        {"^", 3},
        {"(", 0},
        {"sin", 4},
        {"cos", 4}
};

string Helper::input() {
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    return expression;
}

void Helper::output(const vector<string>& outputNotation) {
    for (const auto& token : outputNotation) {
        cout << token << "; ";
    }
    cout << endl;
}

string Helper::processDigitExpression(const string& expression, size_t& i, vector<string>& updatedExpression, bool isNumber) {
    string number(1, expression[i]);

    auto k = i + 1;
    while (k < expression.length() && (std::isdigit(expression[k]) || expression[k] == '.')) {
        number += expression[k];
        i = k;
        k++;
    }

    if (isNumber) {
        updatedExpression.push_back(number);
    }

    return number;
}

bool Helper::elementOperator(const std::string& element) {
    const unordered_map<string, int> operators = {
            {"(", 0}, {")", 0}, {"+", 1}, {"-", 1}, {"/", 2}, {"*", 2}, {"^", 3}, {"sin", 4}, {"cos", 4}
    };
    return operators.find(element) != operators.end();
}

int Helper::getPrecedence(const string& element) {
    auto it = MyDictionary.find(element);
    if (it != MyDictionary.end()) {
        return it->second;
    }
    return -1;
}