#include <iostream>
#include "Tokenization.h"
#include "Helper.h"
#include "PostfixNotation.h"
#include "Counting.h"

using namespace std;

int main() {
    Tokenization tokenization;
    Helper helperProgram;
    Counting counting;

    while (true) {
        string expression = helperProgram.input();
        if (expression == "quit") {
            break;
        }

        vector<string> updatedExpression = tokenization.tokenizeExpression(expression);

        cout << "Tokenization: ";
        helperProgram.output(updatedExpression);

        PostfixNotation notationPost;
        vector<string> notation = notationPost.notation(updatedExpression);

        cout << "Postfix Notation: ";
        helperProgram.output(notation);

        string result = counting.countingPostfix(notation);

        cout << "Final Result: " << result << std::endl;
    }

    return 0;
}