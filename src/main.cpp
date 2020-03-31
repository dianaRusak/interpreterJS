#include <iostream>
#include "gen/JavaScriptLexer.h"
#include "gen/JavaScriptParser.h"
#include "antlr4-runtime.h"
//#include ""
using namespace antlr4;

int main() {
    ANTLRInputStream input("var a = 4;");
    JavaScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    JavaScriptParser parser(&tokens);
    tree::ParseTree *tree = parser.program();

    std::cout << tree->toStringTree(&parser) << std::endl;
    return 0;
}
