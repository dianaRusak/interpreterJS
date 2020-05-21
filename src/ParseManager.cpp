#include <iostream>
#include "gen/JavaScriptLexer.h"
#include "gen/JavaScriptParser.h"
#include "antlr4-runtime.h"
#include "string"
#include "Visitor.h"
#include "ParseManager.h"
#include <fstream>

using namespace antlr4;

std::string ParseManager::Parse() {

    std::ifstream fin(this->inPath);
    std::string buf((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    ANTLRInputStream input(buf);
    JavaScriptLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    JavaScriptParser parser(&tokens);

    try {

        tokens.fill();
        Visitor visitor;

        tree::ParseTree *tree = parser.program();
        visitor.visit(tree);
        auto result = visitor.getTreeString().str();
//        auto result = tree->toStringTree(&parser, true);
        if (!outPath.empty()) {
            std::ofstream fout(this->outPath);
            fout << result;
        }

        return result;

    }catch(LexerNoViableAltException &lexerNoViableAltException) {
        std::cout << "Error" << &lexerNoViableAltException;
        return "";
    }catch (ParseCancellationException &parseCancellationException){
        std::cout << "Error" << &parseCancellationException;
        return "";
    }
}

ParseManager::ParseManager(const std::string &input, const std::string &output) {
    this->inPath = input;
    this->outPath = output;
}
