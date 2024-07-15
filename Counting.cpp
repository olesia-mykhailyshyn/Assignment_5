#include "Counting.h"
#include <stack>
#include <cmath>
#include <sstream>

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
                result = pow(stack.top(), operand2);
                stack.pop();
            }
            else if (token == "sin") {
                result = sin(operand2);
            }
            else if (token == "cos") {
                result = cos(operand2);
            }

            stack.push(result);
        }
    }

    return to_string(stack.top());
}