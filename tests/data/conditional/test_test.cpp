#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("conditional_1", "[conditional]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("conditional_2", "[conditional]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("conditional_3", "[conditional]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
