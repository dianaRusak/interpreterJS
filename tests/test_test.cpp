#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <filesystem>
#include <ParseManager.h>
#include <vector>

std::vector<std::string> getFiles(const std::string& path) {
    std::vector<std::string> test_files;
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.path().extension() == ".in" || entry.path().extension() == ".out") {
            test_files.push_back(entry.path());
        }
    }

    std::sort(test_files.begin(), test_files.end());
    return test_files;
}

void run(const std::vector<std::string>& testFiles, const std::string& group) {
    int j = 1;
    for (int i = 0; i < int(testFiles.size()); i+=2) {
        SECTION(group + std::to_string(j)) {
            std::string inPath(testFiles[i]), outPath(testFiles[i + 1]);
            ParseManager pm(inPath);
            std::string result = pm.Parse();

            std::ifstream expectedTreeFile(outPath);
            std::string expected(
                    (std::istreambuf_iterator<char>(expectedTreeFile)),
                    std::istreambuf_iterator<char>());

            REQUIRE(expected == result);
        }
        ++j;
    }
}

TEST_CASE("additive", "[additive]") {
    const std::string group = "additive";
    run(getFiles(group), group);
}

TEST_CASE("array", "[array]") {
    const std::string group = "array";
    run(getFiles(group), group);
}

TEST_CASE("assignment", "[assignment]") {
    const std::string group = "assignment";
    run(getFiles(group), group);
}

TEST_CASE("binary", "[binary]") {
    const std::string group = "binary";
    run(getFiles(group), group);
}

TEST_CASE("binary-bitwise", "[binary-bitwise]") {
    const std::string group = "binary-bitwise";
    run(getFiles(group), group);
}

TEST_CASE("binary-logical", "[binary-logical]") {
    const std::string group = "binary-logical";
    run(getFiles(group), group);
}

TEST_CASE("bitwise-shift", "[bitwise-shift]") {
    const std::string group = "bitwise-shift";
    run(getFiles(group), group);
}

TEST_CASE("complex", "[complex]") {
    const std::string group = "complex";
    run(getFiles(group), group);
}

TEST_CASE("conditional", "[conditional]") {
    const std::string group = "conditional";
    run(getFiles(group), group);
}

TEST_CASE("equality", "[equality]") {
    const std::string group = "equality";
    run(getFiles(group), group);
}

TEST_CASE("left-hand-side", "[left-hand-side]") {
    const std::string group = "left-hand-side";
    run(getFiles(group), group);
}

TEST_CASE("multiplicative", "[multiplicative]") {
    const std::string group = "multiplicative";
    run(getFiles(group), group);
}

TEST_CASE("numeric-literal", "[numeric-literal]") {
    const std::string group = "numeric-literal";
    run(getFiles(group), group);
}

TEST_CASE("object", "[object]") {
    const std::string group = "object";
    run(getFiles(group), group);
}

TEST_CASE("other", "[other]") {
    const std::string group = "other";
    run(getFiles(group), group);
}

TEST_CASE("postfix", "[postfix]") {
    const std::string group = "postfix";
    run(getFiles(group), group);
}

TEST_CASE("relational", "[relational]") {
    const std::string group = "relational";
    run(getFiles(group), group);
}

TEST_CASE("statement", "[statement]") {
    const std::string group = "statement";
    run(getFiles(group), group);
}

TEST_CASE("tokenize", "[tokenize]") {
    const std::string group = "tokenize";
    run(getFiles(group), group);
}

TEST_CASE("unary", "[unary]") {
    const std::string group = "unary";
    run(getFiles(group), group);
}
