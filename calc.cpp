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

int main(int argc, char *argv[]){
    cout << "======== Calculator ========" << endl;

    // Initialized variables
    Token tok;
    vector<Token> postfix;
    stack<Token> stack;


    tok.get(cin);

    while (tok.value() != "q"){
        // Infix to postfix expression
        while(tok.type() != EOL_T){
            if(tok.type() != ERROR_T){
                if(tok.type() == NUM_INT || tok.type() == NUM_REAL){
                    postfix.push_back(tok);
                }
                else if(tok.type() == LPAREN_T){
                    stack.push(tok);
                }
                else if (tok.type() == RPAREN_T) {
                    while (!stack.empty() && stack.top().type() != LPAREN_T) {
                        postfix.push_back(stack.top());
                        stack.pop();
                    } 
                    stack.pop();
                }
                else if (tok.type() == ADDOP_T || tok.type() == MULOP_T){
                    if (!stack.empty()) {
                        while(!stack.empty() && stack.top().type() >= tok.type()) {
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                        stack.push(tok);
                    }
                    else{
                        stack.push(tok);
                    }
                }

            }

            tok.get(cin);
        }
        
        // Puts the rest of operators to the postfix expression
        while (!stack.empty()) {
            postfix.push_back(stack.top());
            stack.pop();
        }

        // Evaluates the postfix expression
        for(auto i : postfix){
            if(i.type() == NUM_INT || i.type() == NUM_REAL){
                stack.push(i);
            }
            else if(i.type() == ADDOP_T || i.type() == MULOP_T){
                Token tok1 = stack.top();
                stack.pop();
                Token tok2 = stack.top();
                stack.pop();

                double sum; 
                Token res; 

                if(i.value() == "*"){
                    sum = multiply(tok2.value(), tok1.value());
                }
                else if (i.value() == "/") {
                    sum = division(tok2.value(), tok1.value());
                }
                else if (i.value() == "+") {
                    sum = additon(tok2.value(), tok1.value());
                }
                else if (i.value() == "-") {
                    sum = subtraction(tok2.value(), tok1.value());
                }

                res.value() = to_string(sum);
                res.type() = NUM_REAL;

                stack.push(res);
            }
        }

        // Prints out the value and clears the stack
        cout << stack.top().value() << endl << "===========================" << endl;

        // Empties the stack
        while (!stack.empty()) {
            stack.pop(); 
        }

        if(stack.empty()){
        }
        else{
            
        }
        // Next line to read
        tok.get(cin);
        
    }

    return 0;
}
