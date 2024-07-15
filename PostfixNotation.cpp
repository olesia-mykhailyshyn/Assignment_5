#include "PostfixNotation.h"
#include "Helper.h"
#include <stack>
#include <queue>

using namespace std;

vector<string> PostfixNotation::notation(const vector<string>& tokens) {
    queue<string> queue;
    vector<string> returnList;
    stack<string> operatorTokens;
    Helper helperPostfix;

    for (const auto& token : tokens) {
        if (!Helper::elementOperator(token)) {  // check if it's a number
            queue.push(token);
        }

        if (Helper::elementOperator(token) && token != "(" && token != ")") {
            while (!operatorTokens.empty() &&
                   Helper::getPrecedence(operatorTokens.top()) >= Helper::getPrecedence(token)) {
                string op = operatorTokens.top();
                operatorTokens.pop();
                queue.push(op);
            }
            operatorTokens.push(token);
        }

        if (token == "(") {
            operatorTokens.emplace("(");
        }

        if (token == ")") {
            while (operatorTokens.top() != "(") {
                std::string op = operatorTokens.top();
                operatorTokens.pop();
                queue.push(op);
            }
            operatorTokens.pop();  // pop the '('
        }
    }

    while (!operatorTokens.empty()) {
        string op = operatorTokens.top();
        operatorTokens.pop();
        queue.push(op);
    }

    while (!queue.empty()) {
        returnList.push_back(queue.front());
        queue.pop();
    }

    return returnList;
}