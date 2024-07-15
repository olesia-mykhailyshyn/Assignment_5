#include <iostream>
#include "Tokenization.h"
#include "Helper.h"
#include "PostfixNotation.h"
#include "Counting.h"
#include "Globals.h"

using namespace std;

int main() {
    Tokenization tokenization;
    Helper helperProgram;
    Counting counting;

    while (true) {
        string expression = Helper::input();
        if (expression == "quit") {
            break;
        }

        vector<string> updatedExpression = Tokenization::tokenizeExpression(expression);

        cout << "Tokenization: ";
        Helper::output(updatedExpression);

        PostfixNotation notationPost;
        vector<string> notation = PostfixNotation::notation(updatedExpression);

        cout << "Postfix Notation: ";
        Helper::output(notation);

        string result = counting.countingPostfix(notation);

        cout << "Final Result: " << result << std::endl;
    }

    return 0;
}
