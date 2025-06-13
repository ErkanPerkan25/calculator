#include "Token.hpp"
#include <ostream>

using namespace std;

static int **DFA=nullptr;
#define ERROR -1
#define NONE 0

string tokenType_str[] = {"ERROR_T", "EOL_T", "ID", "RPAREN_T", "LPAREN_T", "NUM_INT", "NUM_REAL", "ADDOP_T", "MULOP_T"};

void
Token::get(istream& is){
    // Determinist Finite Automata table, initalize if not done already
    if (!DFA) {
        DFA = new int*[9];

        for(int state=0; state < 9; state++){
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

        DFA[NONE][(int) '\n'] = EOL_T;

        // Filling the tabel with the characters for the states
        for(char ch='0'; ch < '9'; ch++)
            DFA[NONE][(int) ch] = NUM_INT;
         
        for(char ch='0'; ch < '9'; ch++)
            DFA[NUM_INT][(int) ch] = NUM_INT;

        for(char ch='a'; ch < 'z'; ch++)
            DFA[NONE][(int) ch] = ID;

        for(char ch='a'; ch < 'z'; ch++)
            DFA[ID][(int) ch] = ID;

        DFA[NUM_INT]['.'] = NUM_REAL;

        for(char ch='0'; ch < '9'; ch++)
            DFA[NUM_REAL][(int) ch] = NUM_REAL;

    }

    _val = "";
    char ch;

    ch = is.get();
    
    if(ch == '\n') 
        _type = EOL_T;

    while(isspace(ch)){
        if (ch=='\n') {
            _type = EOL_T;
            break;
        }
        ch = is.get();
    }

    if(ch == '\n'){
        _type = EOL_T;
        return;
    }

    is.putback(ch);

    int curr = NONE;
    int prev = ERROR;

    while(curr!=ERROR){
        // gets character
        ch = is.get();

        // sets the previous and move the next based character
        prev = curr;
        curr = DFA[curr][(int) ch];

        // if char is valid, add it to the lexem val
        if(curr!=ERROR){
            _val += ch;
        }

    }

    // sets the token type
    _type = (TokenType) prev;

    if(is)
        is.putback(ch);
}

ostream&
Token::print(ostream& os) const{
    os << "Token value: " << _val << endl << "Token Type: " << tokenType_str[_type] << endl;
    return os;
}

