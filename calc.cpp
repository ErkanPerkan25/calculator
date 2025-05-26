#include <iostream>
#include <string>
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
    Token tok;

    tok.get(cin);

    while(tok.type()!=EOL_T){
        if(tok.type() != ERROR_T){
            cout << tok << endl;
        }
        tok.get(cin);
    }

    return 0;
}
