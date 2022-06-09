#include <tokeniser.h>
#include <vector>
#include <string>
#include <iostream>

std::string getword(std::string code, int idx) {
    std::string word = "";

    for (int i = idx; i < code.length(); i++) {
        if (code[i] == ' '||code[i] == '\n'||code[i] == '('||code[i]==')'||code[i]=='{'||code[i]=='}'||code[i]=='['||code[i]==']'||code[i]==';') {
            break;
        } else {
            word += code[i];
        }
    }
    
    return word;
}   



std::vector<Token> tokeniser(std::string code) {
    std::vector<Token> tokens;
    Token token;
    std::string token_value = "";
    TokenTypes token_type = TokenTypes::TT_UNKNOWN;

    std::vector<std::string> keywords;
    keywords.push_back("int");
    keywords.push_back("char");
    keywords.push_back("float");
    keywords.push_back("string");
    keywords.push_back("return");
    keywords.push_back("if");
    keywords.push_back("else");
    keywords.push_back("while");
    keywords.push_back("for");
    keywords.push_back("break");
    keywords.push_back("void");

    for (int i = 0; i < code.length(); i++) {
        char c = code[i];
        if (c == ' ' || c == '\n' || c == '\t') {
            continue;
        } else if (c == '+') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '-') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '*') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '/') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '=') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '<') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '>') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '!') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '&') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '|') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '(') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == ')') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '{') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == '}') {
            token.value = c;
            token.type = TT_OP;
        } else if (c == ';') {
            token.value = c;
            token.type = TT_OP;
        } else {
            token.value = getword(code, i);
            bool isKeyword;
            for (std::string keyword : keywords) {
                if (token.value == keyword) {
                    token.type = TT_KEYWORD;
                    i += token.value.length() - 1;
                    isKeyword = true;
                    break;
                }
            }
            if (!isKeyword) {
                token.type = TT_IDEN;
                if (token.value.find_first_not_of("0123456789") == std::string::npos) {
                    token.type = TT_NUM;
                } else if (token.value.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-0123456789") == std::string::npos) {
                    token.type = TT_IDEN;
                } else {
                    token.type = TT_UNKNOWN;
                }
                i += token.value.length()-1;
            }
            
        }
        
        
        tokens.push_back(token);
    }
    return tokens;
}