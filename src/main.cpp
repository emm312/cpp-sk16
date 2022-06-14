#include <vector>
#include <tokeniser.h>
#include <parser.h>
#include <iostream>
#include <fstream>

std::string enumToStr(TokenTypes type) {
    switch (type) {
        case TT_IDEN:
            return "TT_IDEN";
        case TT_OP:
            return "TT_OP";
        case TT_NUM:
            return "TT_NUM";
        case TT_STR:
            return "TT_STR";
        case TT_INT:
            return "TT_INT";
        case TT_KEYWORD:
            return "TT_KEYWORD";
        case TT_PAREN:
            return "TT_PAREN";
        case TT_SEMICOLON:
            return "TT_SEMICOLON";
        case TT_BRACE:
            return "TT_BRACE";
        case TT_UNKNOWN:
            return "TT_UNKNOWN";
        default:
            return "UNKNOWN";
    }
}
int main(int argc, char **argv) {
    // open the file at the given path
    std::string path = argv[1];
    std::ifstream file(path);
    std::string code = "";
    std::string line = "";
    while (std::getline(file, line)) {
        code += line;
    }
    std::cout << "Code: " << code << "\n";
    
    std::vector<Token> tokens = tokeniser(code);
    parse(tokens);
    std::cout << "Tokens:\n";
    for (Token t : tokens) {
        std::cout << t.value << " - " << enumToStr(t.type) << '\n';
    }
}



