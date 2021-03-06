//
// Created by botinok on 21.04.2020.
//

#include "Visitor.h"
#include "antlr4-runtime.h"

antlrcpp::Any Visitor::visitProgram(JavaScriptParser::ProgramContext *ctx) {
    treeString << "Program Start" << std::endl;
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


antlrcpp::Any Visitor::visitVariableDeclarationList(JavaScriptParser::VariableDeclarationListContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "VariableDeclarationList" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;

}

antlrcpp::Any Visitor::visitVarModifier(JavaScriptParser::VarModifierContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    if (ctx->let()) {
        treeString << ctx->let()->getText() << " will not be implemented"<< std::endl;
    }
    if (ctx->Var()) {
        treeString << ctx->Var()->getText() << std::endl;
    }
    if (ctx->Const()) {
        treeString << ctx->Const()->getText() << std::endl;
    }

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
    std::string lit;
    if (ctx->NonStrictLet() ) {
        treeString << ctx->NonStrictLet()->getText() + " will not be implemented"<< std::endl;
    }
    if (ctx->Async()){
        treeString << ctx->Async()->getText() + " will not be implemented"<< std::endl;
    }
    if (ctx->Identifier()) lit = " " + ctx->Identifier()->getText();
    treeString << "Identifier " << lit << std::endl;
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
    std::string lit;
    if (ctx->PowerAssign()) lit = ctx->PowerAssign()->getText();
    else if (ctx->BitOrAssign()) lit = ctx->BitOrAssign()->getText();
    else if (ctx->BitXorAssign()) lit = ctx->BitXorAssign()->getText();
    else if (ctx->BitAndAssign()) lit = " " + ctx->BitAndAssign()->getText();
    else if (ctx->RightShiftLogicalAssign()) lit = " " + ctx->RightShiftLogicalAssign()->getText();
    else if (ctx->RightShiftArithmeticAssign()) lit = " " + ctx->RightShiftArithmeticAssign()->getText();
    else if (ctx->LeftShiftArithmeticAssign()) lit = " " + ctx->LeftShiftArithmeticAssign()->getText();
    else if (ctx->PlusAssign()) lit = " " + ctx->PlusAssign()->getText();
    else if (ctx->ModulusAssign()) lit = " " + ctx->ModulusAssign()->getText();
    else if (ctx->DivideAssign()) lit = " " + ctx->DivideAssign()->getText();
    else if (ctx->MultiplyAssign()) lit = " " + ctx->MultiplyAssign()->getText();

    treeString << lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBitNotExpression(JavaScriptParser::BitNotExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BitNotExpression " + ctx->BitNot()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPowerExpression(JavaScriptParser::PowerExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PowerExpression " + ctx->Power()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitDeleteExpression(JavaScriptParser::DeleteExpressionContext *ctx) {
    treeString << ctx->Delete()->getText() << " will not be implemented" << std::endl;
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
    if (ctx->New()) {
        treeString << ctx->New()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Void()) {
        treeString << ctx->Void()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Continue()) key = ctx->Continue()->getText();
    if (ctx->For()) key = ctx->For()->getText();
    if (ctx->While()) key = ctx->While()->getText();
    if (ctx->Function()) key = ctx->Function()->getText();
    if (ctx->This()) key = ctx->This()->getText();
    if (ctx->Default()) key = ctx->Default()->getText();
    if (ctx->Delete()) key = ctx->Delete()->getText();
    if (ctx->In()) key = ctx->In()->getText();
    if (ctx->Try()) {
        treeString << ctx->Try()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Instanceof()) {
        treeString << ctx->Instanceof()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Case()) {
        treeString << ctx->Case()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Catch()) {
        treeString << ctx->Catch()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Finally()) {
        treeString << ctx->Finally()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Switch()){
        treeString << ctx->Switch()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Debugger()){
        treeString << ctx->Debugger()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->With()) {
        treeString << ctx->With()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Throw()){
        treeString << ctx->Throw()->getText() + "will not be implemented";
        return 1;
    }
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
    if (ctx->Static()){
        treeString << ctx->Static()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Yield()){
        treeString << ctx->Yield()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Async()){
        treeString << ctx->Async()->getText() + "will not be implemented";
        return 1;
    }
    if (ctx->Await()){
        treeString << ctx->Await()->getText() + "will not be implemented";
        return 1;
    }
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
    treeString << "FormalParameterArg" << " " + lit << "( " << std::endl;
    auto vc = visitChildren(ctx);
    printWhiteSpace();
    treeString << ")" << std::endl;
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
    if (ctx->Async()) lit1 = " " + ctx->Async()->getText() + " will not be  implemented";
    treeString << "visitAnoymousFunctionDecl" << lit1 << lit << std::endl;

    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    else if (ctx->CloseBrace()) {
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
    if (ctx->This()) lit = " " + ctx->This()->getText();
    treeString << "ThisExpression" << lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;

}

antlrcpp::Any Visitor::visitInExpression(JavaScriptParser::InExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->In()) lit = " " + ctx->In()->getText();
    treeString << "InExpression" << lit << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitInstanceofExpression(JavaScriptParser::InstanceofExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "InstanceofExpression will not be implemented" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitIfStatement(JavaScriptParser::IfStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "IfStatement " << ctx->If()->getText() << lit << std::endl;
    if (ctx->expressionSequence()) visitExpressionSequence(ctx->expressionSequence());
    for (int i = 0; i < ctx->statement().size(); i++){
        visitStatement(ctx->statement(i));
        if (ctx->Else() && i + 1 < ctx->statement().size()){
            printWhiteSpace();
            treeString << ctx->Else()->getText() << std::endl;
        }
    }
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitBlock(JavaScriptParser::BlockContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenBrace()) {
        treeString << ctx->OpenBrace()->getText() << std::endl;
    }auto vc = visitChildren(ctx);
    if (ctx->CloseBrace()) {
        printWhiteSpace();
        treeString << ctx->CloseBrace()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitWithStatement(JavaScriptParser::WithStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->With()) lit1 = "will not be  implemented";
    treeString << "With " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitWhileStatement(JavaScriptParser::WhileStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "WhileStatement " << ctx->While()->getText() << lit<< std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitBreakStatement(JavaScriptParser::BreakStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "BreakStatement " << ctx->Break()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitContinueStatement(JavaScriptParser::ContinueStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "ContinueStatement " << ctx->Continue()->getText() <<  std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitDebuggerStatement(JavaScriptParser::DebuggerStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "DebuggerStatement will not be implemented" <<  std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitForInStatement(JavaScriptParser::ForInStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "ForInStatement " << ctx->For()->getText() << lit << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitForStatement(JavaScriptParser::ForStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "ForStatement " << ctx->For()->getText() << lit << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitForOfStatement(JavaScriptParser::ForOfStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "ForOfStatement " << ctx->For()->getText() << lit << std::endl;
    auto vc = visitChildren(ctx);
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitDoStatement(JavaScriptParser::DoStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit;
    bool b = false;
    if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
    treeString << "DoStatement " << ctx->Do()->getText() << lit << std::endl;
//    auto vc = visitChildren(ctx);
    lit = "";
    if (ctx->statement()) visitStatement(ctx->statement());
    if (ctx->While()){
        printWhiteSpace();
        if (ctx->OpenParen()) lit = " " + ctx->OpenParen()->getText();
        treeString << ctx->While()->getText() << lit << std::endl;
        b = true;
    }
    if (ctx->expressionSequence()) visitExpressionSequence(ctx->expressionSequence());
    if (b && ctx->CloseParen()){
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    if (ctx->CloseParen()) {
        printWhiteSpace();
        treeString << ctx->CloseParen()->getText() << std::endl;
    }
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitPostDecreaseExpression(JavaScriptParser::PostDecreaseExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PostDecreaseExpression " << ctx->MinusMinus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitPostIncrementExpression(JavaScriptParser::PostIncrementExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    treeString << "PostIncrementExpression " << ctx->PlusPlus()->getText() << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitFunctionDeclaration(JavaScriptParser::FunctionDeclarationContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit, lit1;
    if (ctx->Function()) lit1 = " " + ctx->Function()->getText();
    if (ctx->Async()) lit1 = " " + ctx->Async()->getText() + " will not be  implemented";
    treeString << "visitFunctionDecl" << lit1 << lit << std::endl;

    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitSwitchStatement(JavaScriptParser::SwitchStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit, lit1;
    if (ctx->Switch()) lit1 = "will not be  implemented";
    treeString << "Switch " << lit1 << lit << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitTryStatement(JavaScriptParser::TryStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit, lit1;
    if (ctx->Try()) lit1 = "will not be  implemented";
    treeString << "Try " << lit1 << lit << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitThrowStatement(JavaScriptParser::ThrowStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Throw()) lit1 = "will not be  implemented";
    treeString << "Throw " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitYieldStatement(JavaScriptParser::YieldStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit, lit1;
    if (ctx->Yield()) lit1 = "will not be  implemented";
    treeString << "Yield " << lit1 << lit << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitArrowFunction(JavaScriptParser::ArrowFunctionContext *ctx) {
    std::string lit1;
    if (ctx->Async()) {
        nesting += 2;
        printWhiteSpace();
        treeString << ctx->Async()->getText() + " will not be implemented" << std::endl;
        nesting -= 2;
        return 1;
    }
    if (ctx->ARROW()) {
        nesting += 2;
        printWhiteSpace();
        treeString << ctx->ARROW()->getText() + " will not be implemented" << std::endl;
        nesting -= 2;
        return 1;
    }
    treeString << "visitArrowFunction" << std::endl;
    auto vc = visitChildren(ctx);
    nesting -= 2;
    return vc;
}

antlrcpp::Any Visitor::visitAwaitExpression(JavaScriptParser::AwaitExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Await()) lit1 = "will not be  implemented";
    treeString << "Await " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitExportDeclaration(JavaScriptParser::ExportDeclarationContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Export()) lit1 = "will not be  implemented";
    treeString << "Export " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitImportStatement(JavaScriptParser::ImportStatementContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Import()) lit1 = "will not be  implemented";
    treeString << "Import " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitExportDefaultDeclaration(JavaScriptParser::ExportDefaultDeclarationContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Export()) lit1 = "will not be  implemented";
    treeString << "Export " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitClassDeclaration(JavaScriptParser::ClassDeclarationContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Class()) lit1 = "will not be  implemented";
    treeString << "Class " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitImportExpression(JavaScriptParser::ImportExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Import()) lit1 = "will not be  implemented";
    treeString << "Import " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

antlrcpp::Any Visitor::visitClassExpression(JavaScriptParser::ClassExpressionContext *ctx) {
    nesting += 2;
    printWhiteSpace();
    std::string lit1;
    if (ctx->Class()) lit1 = "will not be  implemented";
    treeString << "Class " << lit1 << std::endl;
    nesting -= 2;
    return 1;
}

