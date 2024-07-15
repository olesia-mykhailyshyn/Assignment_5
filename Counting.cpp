#include "Counting.h"
#include <stack>
#include <cmath>
#include <sstream>
#include <algorithm> // for std::max and std::min

using namespace std;

string Counting::countingPostfix(const vector<string>& notation) {
    stack<double> stack;
    double result = 0;

    for (const auto& token : notation) {
        double operand;
        istringstream iss(token);

        if (iss >> operand) {
            stack.push(operand);
        }
        else {
            double operand2 = stack.top();
            stack.pop();

            if (token == "+") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 + operand2;
            }
            else if (token == "-") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 - operand2;
            }
            else if (token == "*") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 * operand2;
            }
            else if (token == "/") {
                double operand1 = stack.top();
                stack.pop();
                result = operand1 / operand2;
            }
            else if (token == "^") {
                double operand1 = stack.top();
                stack.pop();
                result = pow(operand1, operand2);
            }
            else if (token == "sin") {
                result = sin(operand2);
            }
            else if (token == "cos") {
                result = cos(operand2);
            }
            else if (token == "max") {
                double operand1 = stack.top();
                stack.pop();
                result = max(operand1, operand2);
            }
            else if (token == "min") {
                double operand1 = stack.top();
                stack.pop();
                result = min(operand1, operand2);
            }
            else if (token == "abs") {
                result = abs(operand2);
            }

            stack.push(result);
        }
    }

    return to_string(stack.top());
}