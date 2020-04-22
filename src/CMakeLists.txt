cmake_minimum_required(VERSION 3.15)
project(testInter)

set(CMAKE_CXX_STANDARD 14)

add_executable(antlr4 main.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptLexer.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptParser.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptParserBaseListener.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptParserBaseVisitor.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptParserListener.cpp
        ${PROJECT_SOURCE_DIR}/gen/JavaScriptParserVisitor.cpp
        ${PROJECT_SOURCE_DIR}/../grammar/JavaScriptLexerBase.cpp
        ${PROJECT_SOURCE_DIR}/../grammar/JavaScriptParserBase.cpp
        ${PROJECT_SOURCE_DIR}/Visitor.cpp
        ${PROJECT_SOURCE_DIR}/Visitor.h
        )

include_directories(${PROJECT_SOURCE_DIR}/gen)

include_directories(/usr/include/antlr4-runtime)

#target_link_libraries(antlr4 /home/botinok/CLionProjects/antlr4/runtime/Cpp/dist/libantlr4-runtime.a)
target_link_libraries(antlr4 /usr/local/lib/libantlr4-runtime.a)