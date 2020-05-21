#include <ParseManager.h>
#include <fstream>
#include "catch.hpp"

TEST_CASE("other_1", "[other]") {
    std::string inPath("test1.in"), outPath("test1.out");
    ParseManager pm(inPath, outPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("other_2", "[other]") {
    std::string inPath("test2.in"), outPath("test2.out");
    ParseManager pm(inPath, outPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}

TEST_CASE("other_3", "[other]") {
    std::string inPath("test3.in"), outPath("test3.out");
    ParseManager pm(inPath, outPath);
    std::string result = pm.Parse();

    std::ifstream expectedTreeFile(outPath);
    std::string expected((std::istreambuf_iterator<char>(expectedTreeFile)), std::istreambuf_iterator<char>());

    REQUIRE(expected == result);
}
