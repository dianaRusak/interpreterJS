#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("relational_1", "[relational]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_2", "[relational]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_3", "[relational]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_4", "[relational]") {
    std::string inPath("test4.in"), outPath("test4.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_5", "[relational]") {
    std::string inPath("test5.in"), outPath("test5.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_6", "[relational]") {
    std::string inPath("test6.in"), outPath("test6.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("relational_7", "[relational]") {
    std::string inPath("test7.in"), outPath("test7.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
