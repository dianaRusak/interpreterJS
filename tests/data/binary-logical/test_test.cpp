#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("binary-logical_1", "[binary-logical]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("binary-logical_2", "[binary-logical]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("binary-logical_3", "[binary-logical]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("binary-logical_4", "[binary-logical]") {
    std::string inPath("test4.in"), outPath("test4.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("binary-logical_5", "[binary-logical]") {
    std::string inPath("test5.in"), outPath("test5.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("binary-logical_6", "[binary-logical]") {
    std::string inPath("test6.in"), outPath("test6.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
