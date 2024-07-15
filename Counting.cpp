#include "Counting.h"
#include "Globals.h"
#include <stack>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

string Counting::countingPostfix(const vector<string>& notation) {
    stack<double> stack;
    double result = 0;
    string lastVarName;

    for (const auto& token : notation) {
        double operand;
        istringstream iss(token);

        if (iss >> operand) {
            stack.push(operand);
        } else if (Globals::isVariableDefined(token)) {
            stack.push(Globals::getVariable(token));
        } else if (token == "=") {
            // Variable assignment
            double value = stack.top();
            stack.pop();
            Globals::setVariable(lastVarName, value);
            result = value;
        } else if (!iss.fail()) {
            lastVarName = token;
        } else {
            // Handle other operators and functions
            double operand2 = stack.top();
            stack.pop();

            if (token == "+") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 + operand2;
            } else if (token == "-") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 - operand2;
            } else if (token == "*") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 * operand2;
            } else if (token == "/") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 / operand2;
            } else if (token == "^") {
                double operand1 = stack.top();
                stack.pop();
                result = pow(operand1, operand2);
            } else if (token == "sin") {
                result = sin(operand2);
            } else if (token == "cos") {
                result = cos(operand2);
            } else if (token == "max") {
                result = operand2;
                while (!stack.empty() && stack.top() <= operand2) {
                    stack.pop();
                }
                if (!stack.empty()) {
                    result = max(stack.top(), operand2);
                    stack.pop();
                }
                stack.push(result);
            } else if (token == "min") {
                result = operand2;
                while (!stack.empty() && stack.top() >= operand2) {
                    stack.pop();
                }
                if (!stack.empty()) {
                    result = min(stack.top(), operand2);
                    stack.pop();
                }
                stack.push(result);
            } else if (token == "abs") {
                result = abs(operand2);
            }
            stack.push(result);
        }
    }

    return to_string(stack.top());
}
