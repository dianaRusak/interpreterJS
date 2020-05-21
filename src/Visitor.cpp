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

antlrcpp::Any Visitor::visitParenthesizedExpression(JavaScriptParser::ParenthesizedExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string arg;
    if (ctx->OpenParen()) arg = " " + ctx->OpenParen()->getText() ;
    treeString << "ParenthesizedExpression" << arg << std::endl;
    auto vc = visitChildren(ctx);

    if (ctx->CloseParen()){
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitVariableStatement(JavaScriptParser::VariableStatementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "VariableDeclaration " << ctx->children.size()<< std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;

}

antlrcpp::Any Visitor::visitVarModifier(JavaScriptParser::VarModifierContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->let()) {
        treeString << ctx->let()->getText() + " will not be implemented"<< std::endl;
    }
    treeString << ctx->Var()->getText() << std::endl;
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
    int buf = nesting;
    for (int i = 0; i < nesting; i++) {
        treeString << "-";
    }
}

antlrcpp::Any Visitor::visitAssignable(JavaScriptParser::AssignableContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any Visitor::visitIdentifier(JavaScriptParser::IdentifierContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->NonStrictLet() || ctx->Async()) {
        treeString << "will not be implemented"<< std::endl;
        return 1;
    }
    treeString << "Identifier " << ctx->Identifier()->getText() << std::endl;
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
    treeString << "UnaryMinusExpression " + ctx->Minus()->getText() << std::endl;
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
    treeString << "AssignmentExpression" << " " + ctx->Assign()->getText() << std::endl;
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

antlrcpp::Any Visitor::visitArguments(JavaScriptParser::ArgumentsContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string arg;
    if (ctx->OpenParen()) arg = " " + ctx->OpenParen()->getText() ;
    treeString << "Arguments" << arg << std::endl;
    auto vc = visitChildren(ctx);

    if (ctx->CloseParen()){
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitMemberDotExpression(JavaScriptParser::MemberDotExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string paren = ctx->Dot() ? " '" + ctx->Dot()->getText() + "' "  :
                        "";
    treeString << "Arguments" << paren << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitExpressionSequence(JavaScriptParser::ExpressionSequenceContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "ExpressionSequence" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPropertyName(JavaScriptParser::PropertyNameContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string nm;
    treeString << "PropertyName" << std::endl;
    if (ctx->OpenBracket()) {
        printWhiteSpace();
        treeString << ctx->OpenBracket()->getText()<< std::endl;
    }
    if (ctx->StringLiteral()){
        printWhiteSpace();
        treeString << ctx->StringLiteral()->getText()<< std::endl;
    }

    auto vc = visitChildren(ctx);

    if (ctx->CloseBracket()){
        printWhiteSpace();
        treeString << ctx->CloseBracket()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}


antlrcpp::Any
Visitor::visitComputedPropertyExpressionAssignment(JavaScriptParser::ComputedPropertyExpressionAssignmentContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string nm;
    if (ctx->OpenBracket()) nm = " " + ctx->OpenBracket()->getText();
    treeString << "ComputedPropertyExpressionAssignment" << nm << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseBracket()){
        printWhiteSpace();
        treeString << " " + ctx->CloseBracket()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitMemberIndexExpression(JavaScriptParser::MemberIndexExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->OpenBracket()) treeString << ctx->OpenBracket()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    printWhiteSpace();
    if (ctx->CloseBracket()){
        printWhiteSpace();
        treeString << " " + ctx->CloseBracket()->getText() << std::endl;
    }
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

antlrcpp::Any Visitor::visitKeyword(JavaScriptParser::KeywordContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string key;
    if (ctx->If()) key = ctx->If()->getText();
    if (ctx->Break()) key = ctx->Break()->getText();
    if (ctx->Do()) key = ctx->Do()->getText();
    if (ctx->Typeof()) key = ctx->Typeof()->getText();
    if (ctx->Else()) key = ctx->Else()->getText();
    if (ctx->New()) key = ctx->New()->getText();
    if (ctx->Void()) key = ctx->Void()->getText();
    if (ctx->Continue()) key = ctx->Continue()->getText();
    if (ctx->For()) key = ctx->For()->getText();
    if (ctx->While()) key = ctx->While()->getText();
    if (ctx->Function()) key = ctx->Function()->getText();
    if (ctx->This()) key = ctx->This()->getText();
    if (ctx->Default()) key = ctx->Default()->getText();
    if (ctx->Delete()) key = ctx->Delete()->getText();
    if (ctx->In()) key = ctx->In()->getText();
    if (ctx->Try()) key = ctx->Try()->getText();
    if (ctx->Instanceof()) key = ctx->Instanceof()->getText();
    if (ctx->Case()) key = ctx->Case()->getText();
    if (ctx->Catch()) key = ctx->Catch()->getText();
    if (ctx->Finally()) key = ctx->Finally()->getText();
    if (ctx->Switch()) key = ctx->Switch()->getText();
    if (ctx->Debugger()) key = ctx->Debugger()->getText();
    if (ctx->With()) key = ctx->With()->getText();
    if (ctx->Throw()) key = ctx->Throw()->getText();
    if (ctx->Class()) key = ctx->Class()->getText();
    if (ctx->Enum()) key = ctx->Enum()->getText();
    if (ctx->Extends()) key = ctx->Extends()->getText();
    if (ctx->Super()) key = ctx->Super()->getText();
    if (ctx->Const()) key = ctx->Const()->getText();
    if (ctx->Export()) key = ctx->Export()->getText();
    if (ctx->Import()) key = ctx->Import()->getText();
    if (ctx->Implements()) key = ctx->Implements()->getText();
    if (ctx->Private()) key = ctx->Private()->getText();
    if (ctx->Public()) key = ctx->Public()->getText();
    if (ctx->Interface()) key = ctx->Interface()->getText();
    if (ctx->Package()) key = ctx->Package()->getText();
    if (ctx->Protected()) key = ctx->Protected()->getText();
    if (ctx->Static()) key = ctx->Static()->getText();
    if (ctx->Yield()) key = ctx->Yield()->getText();
    if (ctx->Async()) key = ctx->Async()->getText();
    if (ctx->Await()) key = ctx->Await()->getText();
    if (ctx->From()) key = ctx->From()->getText();
    if (ctx->As()) key = ctx->As()->getText();
    treeString << "Keyword " << key << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitReservedWord(JavaScriptParser::ReservedWordContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string key;
    if (ctx->BooleanLiteral()) key = " " + ctx->BooleanLiteral()->getText();
    if (ctx->NullLiteral()) key = " " + ctx->NullLiteral()->getText();
    treeString << "ReservedWord" << key << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitElementList(JavaScriptParser::ElementListContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "ElementList" << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->children.size() == 0){
        nesting += 2;
        printWhiteSpace();
        treeString << "null" << std::endl;
        nesting -= 2;
    }
    nesting -= 2;
    return vc;
}


antlrcpp::Any Visitor::visitLiteral(JavaScriptParser::LiteralContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->NullLiteral()) lit = " " + ctx->NullLiteral()->getText();
    if (ctx->BooleanLiteral()) lit = " " + ctx->BooleanLiteral()->getText();
    if (ctx->StringLiteral()) lit = " " + ctx->StringLiteral()->getText();
    if (ctx->TemplateStringLiteral()) lit = " " + ctx->TemplateStringLiteral()->getText();
    if (ctx->RegularExpressionLiteral()) lit = " " + ctx->RegularExpressionLiteral()->getText();
    treeString << "Literal" << lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitObjectLiteralExpression(JavaScriptParser::ObjectLiteralExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "ObjectLiteral {" << std::endl;
    auto vc = visitChildren(ctx);
    printWhiteSpace();
    treeString << '}' << std::endl;
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPropertyExpressionAssignment(JavaScriptParser::PropertyExpressionAssignmentContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PropertyExpressionAssignment"<< std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitFunctionProperty(JavaScriptParser::FunctionPropertyContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "FunctionProperty" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitGetter(JavaScriptParser::GetterContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "Getter" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitFunctionBody(JavaScriptParser::FunctionBodyContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "FunctionBody {" << std::endl;
    auto vc = visitChildren(ctx);
    printWhiteSpace();
    treeString << "}" << std::endl;
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitSetter(JavaScriptParser::SetterContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "Setter" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitReturnStatement(JavaScriptParser::ReturnStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "Statement" << " " + ctx->Return()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPropertySetter(JavaScriptParser::PropertySetterContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    else if (ctx->OpenBrace()) lit = " " + ctx->OpenBrace()->getText();
    treeString << "PropertySetter" + lit << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    else if (ctx->CloseBrace()) {
        printWhiteSpace();
        treeString <<  " " + ctx->CloseBrace()->getText() << std::endl;
    }

    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitFormalParameterArg(JavaScriptParser::FormalParameterArgContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->Assign()) lit = " " + ctx->Assign()->getText();
    treeString << "FormalParameterArg" << " " + lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitAnoymousFunctionDecl(JavaScriptParser::AnoymousFunctionDeclContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit, lit1;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    else if (ctx->OpenBrace()) lit = " " + ctx->OpenBrace()->getText();
    if (ctx->Function()) lit1 = " " + ctx->Function()->getText();
    if (ctx->Async()) lit1 = "will not be  implemented";
    treeString << "visitAnoymousFunctionDecl" << lit1 << lit << std::endl;

    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    if (ctx->CloseBrace()) {
        printWhiteSpace();
        treeString <<  " " + ctx->CloseBrace()->getText() << std::endl;
    }nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitArrowFunctionParameters(JavaScriptParser::ArrowFunctionParametersContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();

    treeString << "ArrowFunctionParameters" << lit << std::endl;

    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitThisExpression(JavaScriptParser::ThisExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->This()) lit = ctx->This()->getText();
    treeString << lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;

}



//antlrcpp::Any Visitor::visitArgumentsExpression(JavaScriptParser::ArgumentsExpressionContext *ctx) {
//    return JavaScriptParserBaseVisitor::visitArgumentsExpression(ctx);
//}

//antlrcpp::Any Visitor::visitLet(JavaScriptParser::LetContext *ctx) {
//    treeString << ctx->NonStrictLet()->getText() << " and " << ctx->StrictLet()->getText() << " will not be implemented"
//               << std::endl;
//}
