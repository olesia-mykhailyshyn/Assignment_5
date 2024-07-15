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
        if (!Helper::elementOperator(token) && token != "=") {  // check if it's a number or variable
            queue.push(token);
        } else if (Helper::elementOperator(token) && token != "(" && token != ")") {
            while (!operatorTokens.empty() && Helper::getPrecedence(operatorTokens.top()) >= Helper::getPrecedence(token)) {
                string op = operatorTokens.top();
                operatorTokens.pop();
                queue.push(op);
            }
            operatorTokens.push(token);
        } else if (token == "(") {
            operatorTokens.emplace("(");
        } else if (token == ")") {
            while (operatorTokens.top() != "(") {
                std::string op = operatorTokens.top();
                operatorTokens.pop();
                queue.push(op);
            }
            operatorTokens.pop();  // pop the '('
        } else if (token == "=") {
            string varName = queue.back(); // Get the variable name from the back of the queue
            queue.pop();
            returnList.push_back(varName);
            operatorTokens.push(token); // Push the assignment operator to the stack
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
