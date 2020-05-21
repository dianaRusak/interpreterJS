#pragma once

#include <string>

class ParseManager {
public:
    explicit ParseManager(const std::string& input = "", const std::string& output = "");
    std::string Parse();
private:
    std::string inPath;
    std::string outPath;
};