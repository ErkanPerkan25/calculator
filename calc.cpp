#include <cstdio>
#include <iostream>
#include <istream>
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
    vector<Token> postfix;
    stack<Token> stack;


    tok.get(cin);

    while(tok.type() != EOL_T){
        if(tok.type() != ERROR_T){
            if(tok.type() == LPAREN_T){
                stack.push(tok);
            }
            else if (tok.type() == RPAREN_T) {
                while (stack.top().value() != "(") {
                    postfix.push_back((stack.top()));
                    stack.pop();
                } 
                stack.pop();
            }
            else if(tok.type() == NUM_INT || tok.type() == NUM_REAL){
                postfix.push_back((tok));
            }
            else{
                while (!stack.empty()) {
                    postfix.push_back((stack.top()));
                    stack.pop();
                }
                stack.push(tok);
            }

        }

        tok.get(cin);
    }

    while (!stack.empty()) {
        postfix.push_back((stack.top()));
        stack.pop();
    }

    for(auto i : postfix){
        cout << i.value() << endl;
    }

    return 0;
}
