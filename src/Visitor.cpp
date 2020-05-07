//
// Created by botinok on 21.04.2020.
//

#include "Visitor.h"
#include "antlr4-runtime.h"

antlrcpp::Any Visitor::visitProgram(JavaScriptParser::ProgramContext *ctx) {
    treeString << "Program Start" << std::endl;
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitSourceElement(JavaScriptParser::SourceElementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitStatement(JavaScriptParser::StatementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitEos(JavaScriptParser::EosContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitVariableStatement(JavaScriptParser::VariableStatementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "VariableDeclaration" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;

}

antlrcpp::Any Visitor::visitVarModifier(JavaScriptParser::VarModifierContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->let()){
        treeString  << ctx->let()->getText() + " will not be implemented";
    }
    treeString << ctx->start->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitVariableDeclaration(JavaScriptParser::VariableDeclarationContext *ctx) {
    nesting += 2;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

void Visitor::printWhiteSpace() {
    for (int i = 0; i < nesting; i++) {
        treeString << " ";
    }
}

antlrcpp::Any Visitor::visitAssignable(JavaScriptParser::AssignableContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitIdentifier(JavaScriptParser::IdentifierContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->NonStrictLet() || ctx->Async()){
        treeString  << "will not be implemented";
        return 1;
    }
    treeString  << "Identifier " << ctx->Identifier()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitNumericLiteral(JavaScriptParser::NumericLiteralContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "NumericLiteral " << ctx->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitAssignmentOperator(JavaScriptParser::AssignmentOperatorContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "Assignmentor " << ctx->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitNotExpression(JavaScriptParser::BitNotExpressionContext *ctx) {
    printWhiteSpace();
    treeString << "BitNotExpression " + ctx->BitNot()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPowerExpression(JavaScriptParser::PowerExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PowerExpression '" + ctx->Power()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitDeleteExpression(JavaScriptParser::DeleteExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "DeleteExpression " + ctx->Delete()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitUnaryMinusExpression(JavaScriptParser::UnaryMinusExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "UnaryMinusExpression '" + ctx->Minus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPreDecreaseExpression(JavaScriptParser::PreDecreaseExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PreDecreaseExpression " << ctx->MinusMinus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitNotExpression(JavaScriptParser::NotExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "NotExpression " << ctx->Not()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitUnaryPlusExpression(JavaScriptParser::UnaryPlusExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "UnaryPlusExpression " << ctx->Plus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPreIncrementExpression(JavaScriptParser::PreIncrementExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PreIncrementExpression " << ctx->PlusPlus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitMultiplicativeExpression(JavaScriptParser::MultiplicativeExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string math_sign = ctx->Multiply() ? ctx->Multiply()->getText() : ctx->Divide() ? ctx->Divide()->getText() :
                                                                           ctx->Modulus()->getText();
    treeString << "MultiplicativeExpression " << math_sign << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitTypeofExpression(JavaScriptParser::TypeofExpressionContext *ctx) {
    treeString << ctx->Typeof()->getText() << " will not be implemented" << std::endl;
    return 0;
}

antlrcpp::Any Visitor::visitVoidExpression(JavaScriptParser::VoidExpressionContext *ctx) {
    treeString << ctx->Void()->getText() << " will not be implemented" << std::endl;
    return 0;
}

antlrcpp::Any Visitor::visitAdditiveExpression(JavaScriptParser::AdditiveExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string math_sign = ctx->Plus() ? ctx->Plus()->getText() : ctx->Minus()->getText();
    treeString << "AdditiveExpression " << math_sign << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitAssignmentExpression(JavaScriptParser::AssignmentExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "AssignmentExpression " << ctx->Assign()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitAndExpression(JavaScriptParser::BitAndExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitAndExpression " << ctx->BitAnd()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitXOrExpression(JavaScriptParser::BitXOrExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitXOrExpression " << ctx->BitXOr()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitOrExpression(JavaScriptParser::BitOrExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitOrExpression " << ctx->BitOr()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitLogicalOrExpression(JavaScriptParser::LogicalOrExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitLogicalOrExpression " << ctx->Or()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitLogicalAndExpression(JavaScriptParser::LogicalAndExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitLogicalAndExpression " << ctx->And()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitShiftExpression(JavaScriptParser::BitShiftExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string math_sign = ctx->LeftShiftArithmetic() ? ctx->LeftShiftArithmetic()->getText()
                                                       : ctx->RightShiftArithmetic()
                                                         ? ctx->RightShiftArithmetic()->getText() :
                                                         ctx->RightShiftLogical()->getText();
    treeString << "BitShiftExpression " << math_sign << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitEqualityExpression(JavaScriptParser::EqualityExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string math_sign = ctx->Equals_() ? ctx->Equals_()->getText() : ctx->NotEquals()
                                                                         ? ctx->NotEquals()->getText()
                                                                         : ctx->IdentityEquals()
                                                                           ? ctx->IdentityEquals()->getText()
                                                                           : ctx->IdentityNotEquals()->getText();
    treeString << "EqualityExpression " << math_sign << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitRelationalExpression(JavaScriptParser::RelationalExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string math_sign = ctx->LessThan() ? ctx->LessThan()->getText() : ctx->MoreThan()
                                                                           ? ctx->MoreThan()->getText()
                                                                           : ctx->LessThanEquals()
                                                                             ? ctx->LessThanEquals()->getText()
                                                                             : ctx->GreaterThanEquals()->getText();
    treeString << "EqualityExpression " << math_sign << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitTernaryExpression(JavaScriptParser::TernaryExpressionContext *ctx) {
    treeString << ctx->QuestionMark()->getText() << " and " << ctx->Colon()->getText() << " will not be implemented"
               << std::endl;
    return 0;
}

antlrcpp::Any Visitor::visitNewExpression(JavaScriptParser::NewExpressionContext *ctx) {
    treeString << ctx->New()->getText() << " will not be implemented" << std::endl;
    return 0;
}


//antlrcpp::Any Visitor::visitArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext *ctx) {
//    return JavaScriptParserBaseVisitor::visitArgumentsExpression(ctx);
//}

//antlrcpp::Any Visitor::visitLet(JavaScriptParser::LetContext *ctx) {
//    treeString << ctx->NonStrictLet()->getText() << " and " << ctx->StrictLet()->getText() << " will not be implemented"
//               << std::endl;
//}
