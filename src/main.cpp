#include <ParseManager.h>
#include <iosfwd>
#include <sstream>

int main() {
    std::string input = "input.txt", output = "output.txt";
    auto pm = new ParseManager(input, output);
    pm->Parse();
    return 0;

}
