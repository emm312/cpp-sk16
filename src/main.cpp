#include <vector>
#include <tokeniser.h>
#include <iostream>

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
        default:
            return "UNKNOWN";
    }
}
int main() {
    std::string code = "int main() { int s = 0; print(s); return 0; }";
    std::vector<Token> tokens = tokeniser(code);
    for (Token t : tokens) {
        std::cout << t.value << " - " << enumToStr(t.type) << '\n';
    }
}



