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
     
    cin >> tok;

    cout << tok << endl;

    return 0;
}
