#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

#include <iostream>
#include <ostream>

enum TokenType{ERROR_T, EOL_T, ID, RPAREN_T, LPAREN_T, NUM_INT, NUM_REAL, ADDOP_T, MULOP_T};

class Token{
private:
    int _type;
    std::string _val;

public:
    // Default Constructor
    Token() : _type(ERROR_T), _val("") {}

    // Constructor
    Token(int type, const std::string &val) : _type(type) , _val("") {}

    // Access and Modifiers
    int type() const {return _type;}
    int& type() {return _type;}

    std::string value() const {return _val;}
    std::string& value() {return _val;}

    // Read the token
    void get(std::istream &is);

    // Prints token
    std::ostream& print(std::ostream &os) const;
};

inline std::ostream& operator<<(std::ostream &os, const Token &tok){
    return tok.print(os);
}


#endif
