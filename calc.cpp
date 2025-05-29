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
            if(tok.type() == ADDOP_T || tok.type() == MULOP_T || tok.type() == LPAREN_T || tok.type() == RPAREN_T){
                
                if(stack.empty() || tok.type() > stack.top().type()){
                    stack.push(tok);
                }
                else{
                    if(!stack.empty()){
                        while(!stack.empty()){
                            if (stack.top().type() >= tok.type()) {
                                postfix.push(stack.top());
                                stack.pop();
                            }
                        }
                    }
                }
            }
            else{
                postfix.push(tok);
            }
            
            if(tok.type() == LPAREN_T){
                stack.push(tok);
            }
            else if (tok.type() == RPAREN_T) {
                while (stack.top().value() != ")") {
                    postfix.push(stack.top());
                    stack.pop();
                } 
            }

            //tok.get(cin);
        }
    }


    if(!stack.empty()){
        while (!stack.empty()) {
            postfix.push(stack.top());
            stack.pop();
        }
    }

    while(!postfix.empty()){
        cout << postfix.top().value() << endl;
        postfix.pop();
    }

    return 0;
}
