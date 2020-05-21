cmake_minimum_required(VERSION 3.15)
project(testInter)

set(CMAKE_CXX_STANDARD 14)

add_library(interpreter_lib STATIC
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
        ${PROJECT_SOURCE_DIR}/ParseManager.h
        ${PROJECT_SOURCE_DIR}/ParseManager.cpp
        )

target_include_directories(interpreter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(interpreter_lib PUBLIC ${PROJECT_SOURCE_DIR}/gen)
target_include_directories(interpreter_lib PUBLIC /usr/include/antlr4-runtime)
target_link_libraries(interpreter_lib PUBLIC /usr/local/lib/libantlr4-runtime.a)

add_executable(interpreter main.cpp)

#include_directories(${PROJECT_SOURCE_DIR}/gen)
#
#include_directories(/usr/include/antlr4-runtime)

#target_link_libraries(antlr4 /home/botinok/CLionProjects/antlr4/runtime/Cpp/dist/libantlr4-runtime.a)
target_link_libraries(interpreter PRIVATE interpreter_lib)
#target_link_libraries(interpreter /usr/local/lib/libantlr4-runtime.a)