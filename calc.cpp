#include <iostream>
#include <string>
#include <stack>
#include <vector>

#include "Token.hpp"

using namespace std;

double additon(string &lhs, string &rhs){
    double sum = stod(lhs) + stod(rhs);
    return sum;
}

double subtraction(string &lhs, string &rhs){
    double sum = stod(lhs) - stod(rhs);
    return sum;
}

double multiply(string &lhs, string &rhs){
    double prod = stod(lhs) * stod(rhs);
    return prod;
}

double division(string &lhs, string &rhs){
    double sum = stod(lhs)/stod(rhs);
    return sum;
}

void evaluate_postfix(){

}

int main(int argc, char *argv[]){
    cout << "======== Calculator ========" << endl;

    Token tok;
    stack<Token> postfix;
    stack<Token> stack;

    tok.get(cin);

    while(tok.type() != EOL_T){
        if(tok.type() != ERROR_T){
            if(tok.type() == LPAREN_T){
                stack.push(tok);
            }
            else if (tok.type() == RPAREN_T) {
                while (stack.top().value() != "(") {
                    postfix.push(stack.top());
                    stack.pop();
                } 
                stack.pop();
            }
            else if(tok.type() == NUM_INT || tok.type() == NUM_REAL){
                postfix.push(tok);
            }
            else{
            }

        }

        if(!stack.empty()){
            while (!stack.empty()) {
                postfix.push(stack.top());
                stack.pop();
            }
        }

        while(!postfix.empty()){
            cout << postfix.top().value() << " ";
            postfix.pop();
        }

        tok.get(cin);
    }


    return 0;
}
