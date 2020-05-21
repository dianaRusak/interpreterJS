#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("postfix_1", "[postfix]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("postfix_2", "[postfix]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("postfix_3", "[postfix]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("postfix_4", "[postfix]") {
    std::string inPath("test4.in"), outPath("test4.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("postfix_5", "[postfix]") {
    std::string inPath("test5.in"), outPath("test5.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("postfix_6", "[postfix]") {
    std::string inPath("test6.in"), outPath("test6.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
