#include "Token.hpp"
#include <ostream>

using namespace std;

static int **DFA=nullptr;
#define ERROR -1
#define NONE 0

istream&
Token::get(istream& is){
    // Determinist Finite Automata table, initalize if not done already
    if (!DFA) {
        DFA = new int*[7];

        for(int state=0; state < 7; state++){
            // Creates a row with 256 columns, the characters
            DFA[state] = new int[256];
            for(int ch=0; ch < 256; ch++){
                DFA[state][ch] = ERROR;
            }
        }

        DFA[NONE][(int) '+'] = ADDOP_T;
        DFA[NONE][(int) '-'] = ADDOP_T;

        DFA[NONE][(int) '*'] = MULOP_T;
        DFA[NONE][(int) '/'] = MULOP_T;

        DFA[NONE][(int) '('] = LPAREN_T;
        DFA[NONE][(int) ')'] = RPAREN_T;

        // Filling the tabel with the characters for the states
        for(char ch='0'; ch < '9'; ch++)
            DFA[NONE][(int) ch] = NUM_INT;
         
        for(char ch='0'; ch < '9'; ch++)
            DFA[NUM_INT][(int) ch] = NUM_INT;

        DFA[NUM_INT]['.'] = NUM_REAL;

        for(char ch='0'; ch < '9'; ch++)
            DFA[NUM_REAL][(int) ch] = NUM_REAL;

    }

    char ch;

    ch = is.get();

    if(!is) 
        _type = ERROR_T;

    while(isspace(ch)){

    }

    if(!is){
        _type = ERROR_T;
    }

    is.putback(ch);

    int curr = NONE;
    int prev = ERROR;

    while(curr!=ERROR){

    }


    // Reads a token, sets value and the type of the token
    return is;
}

ostream&
Token::print(ostream& os) const{
    os << "Token value: " << _val << endl << "Token Type: " << _type << endl;
    return os;
}

