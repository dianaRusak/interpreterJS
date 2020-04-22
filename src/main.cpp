#include <iostream>
#include "gen/JavaScriptLexer.h"
#include "gen/JavaScriptParser.h"
#include "antlr4-runtime.h"
#include "string"
#include "Visitor.h"

using namespace antlr4;

int main() {
    ANTLRInputStream input("a || b && c | d ^ e & f == g < h >>> i + j * k");
    JavaScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    JavaScriptParser parser(&tokens);

    tokens.fill();
    Visitor visitor;

    tree::ParseTree *tree = parser.program();
    visitor.visit(tree);
    std::cout << visitor.getTreeString().str();
//    std::cout << tree->toStringTree(&parser, true) << std::endl;

    return 0;

}
