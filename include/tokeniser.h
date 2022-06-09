#ifndef TOKENISER_H
#define TOKENISER_H
#include <vector>
#include <string>

enum TokenTypes {
    TT_IDEN,
    TT_OP,
    TT_NUM,
    TT_STR,
    TT_INT,
    TT_KEYWORD,
    TT_UNKNOWN
};


struct Token {
    std::string value;
    TokenTypes type;
};


std::vector<Token> tokeniser(std::string code);
#endif