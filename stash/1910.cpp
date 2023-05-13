#include <iostream>
#include <string>
#include <vector>
using namespace std;
string removeOccurrences(string s, string part) {
    std::string stack;
    stack.reserve(10);
    for (int i = 0; i < s.size(); i++) {
        stack.push_back(s[i]);
        auto p = stack.rfind(part);
        if (p != std::string::npos) {
            stack.erase(p);
        }
        printf("%s\n", stack.c_str());
    }

    return stack;
}

main() {
    std::string s = "aabababcccbcxy";
    removeOccurrences(s, "abc");
    return 0;
}