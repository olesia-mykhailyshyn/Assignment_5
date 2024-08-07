#include "Tokenization.h"
#include "Helper.h"
#include "Globals.h"

using namespace std;

vector<string> Tokenization::tokenizeExpression(const string& expression) {
    vector<string> updatedExpression;
    Helper helper;
    size_t i = 0;

    while (i < expression.length()) {
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || !isdigit(expression[i - 1])))) {
            Helper::processDigitExpression(expression, i, updatedExpression, true);
        } else if (Helper::elementOperator(string(1, expression[i]))) {
            updatedExpression.emplace_back(1, expression[i]);
        } else if (isalpha(expression[i])) {
            string varName(1, expression[i]);
            while (++i < expression.length() && isalnum(expression[i])) {
                varName += expression[i];
            }
            --i;
            updatedExpression.push_back(varName);
        } else if (expression[i] == '=') {
            updatedExpression.emplace_back(1, expression[i]);
        }
        else if ((i + 2 < expression.length()) &&
                 ((expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n') ||
                  (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's') ||
                  (expression[i] == 'm' && expression[i + 1] == 'a' && expression[i + 2] == 'x') ||
                  (expression[i] == 'm' && expression[i + 1] == 'i' && expression[i + 2] == 'n') ||
                  (expression[i] == 'a' && expression[i + 1] == 'b' && expression[i + 2] == 's'))) {
            string func = expression.substr(i, 3);
            updatedExpression.push_back(func);
            i += 2;
        }
        ++i;
    }
    return updatedExpression;
}
