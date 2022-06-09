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
    keywords.push_back("continue");
    keywords.push_back("void");

    for (int i = 0; i < code.length(); i++) {
        char c = code[i];
        if (c == ' ' || c == '\n' || c == '\t') {
            continue;
        } else if (c == '+') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '-') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '*') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '/') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '=') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '<') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '>') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '!') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '&') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '|') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '(') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == ')') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '{') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == '}') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == ';') {
            token_value = c;
            token_type = TT_OP;
        } else if (c == ' ' || c =='\n' || c =='\t') {
            continue;
        } else {
            token_value = getword(code, i);
            bool isKeyword;
            isKeyword = false;
            for (std::string keyword : keywords) {
                if (token_value == keyword) {
                    token_type = TT_KEYWORD;
                    i += token_value.length() - 1;
                    isKeyword = true;
                    break;
                }
            }
            if (!isKeyword) {
                token_type = TT_IDEN;
                if (token_value.find_first_not_of("0123456789") == std::string::npos) {
                    token_type = TT_NUM;
                } else if (token_value.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_0123456789") == std::string::npos) {
                    token_type = TT_IDEN;
                } else {
                    token_type = TT_UNKNOWN;
                }
                i += token_value.length()-1;
            }
            
        }
        Token token_to_push;
        token_to_push.type = token_type;
        token_to_push.value = token_value;
        tokens.push_back(token_to_push);
    }
    return tokens;
}