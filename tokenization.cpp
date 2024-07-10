#include <list>
#include <string>

using namespace std;

class Tokenization {
    public:
    bool ElementOperator (const string& element)
        {
            const char* operators[9] = { "(", ")", "+", "-", "/", "*", "^", "sin", "cos" };
            for (int i = 0; i < 9; i++)
            {
                if (operators[i] == element)
                {
                    return true;
                }
            }
            return false;
        }

    list<string> TokenizationExpression(const string& expression) {
        list<string> updatedExpression;
        for (int i = 0; i < expression.length(); i++) {
            string number = to_string(expression[i]);

            if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || !isdigit(expression[i - 1])))) {
                for (int k = i + 1; k < expression.length() && (isdigit(expression[k]) || expression[k] == '.'); k++) {
                    number += expression[k];
                    i = k;
                }
                if (isdigit(stoi(number))) {  //isNumber
                    updatedExpression.push_back(number);
                }
                //return number
            }

            else if (ElementOperator(to_string(expression[i]))) {
                updatedExpression.push_back(to_string(expression[i]));
            }

            else if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n' ||
                     (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's'))
            {
                string func = "{expression[i]}{expression[i + 1]}{expression[i + 2]}";
                updatedExpression.push_back(func);
            }
        }
        return updatedExpression;
    }
};