#include <iostream>
#include <string>

#include "dbg.h"

using namespace std;
string reverseWords(string s) {
    std::string res;
    const int sz = s.size();
    if (s.empty()) return "";
    int p1 = 0, p2 = 0;
    while (true) {
        while (s[p1] == ' ' && p1 < sz) {
            ++p1;
        }
        if (p1 == sz) break;
        p2 = p1;
        while (s[p2] != ' ' && p2 < sz) {
            ++p2;
        }
        res = s.substr(p1, p2 - p1) + " " + res;
        p1 = p2;
        if (p2 == sz) break;
    }
    res.pop_back();

    return res;
}
int main(int argc, char const *argv[]) {
    std::cout << "[" << reverseWords("the sky is blue") << "]";
    return 0;
}
