#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("numeric-literal_1", "[numeric-literal]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("numeric-literal_2", "[numeric-literal]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("numeric-literal_3", "[numeric-literal]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("numeric-literal_4", "[numeric-literal]") {
    std::string inPath("test4.in"), outPath("test4.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("numeric-literal_5", "[numeric-literal]") {
    std::string inPath("test5.in"), outPath("test5.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
TEST_CASE("numeric-literal_6", "[numeric-literal]") {
    std::string inPath("test6.in"), outPath("test6.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
TEST_CASE("numeric-literal_7", "[numeric-literal]") {
    std::string inPath("test7.in"), outPath("test7.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
TEST_CASE("numeric-literal_8", "[numeric-literal]") {
    std::string inPath("test8.in"), outPath("test8.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
