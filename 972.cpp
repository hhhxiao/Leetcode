#include <iostream>
#include <string>

using namespace std;
// "1.121212"

void parse(const std::string &s, int &a, int &b) {
    int pi = 0;
    int index = 0;
    while (index < s.size() && s[index] != '.') {
        pi *= 10;
        pi += (s[index] - '0');
        ++index;
    }
    if (index >= s.size() - 1) {
        a = pi;
        b = 1;
        return;
    }

    int lim = 0;
    int ten = 1;
    index++;
    while (index < s.size() && s[index] != '(') {
        lim *= 10;
        lim += (s[index] - '0');
        ten *= 10;
        ++index;
    }

    if (index >= s.size()) {
        a = pi * ten + lim;
        b = ten;
        return;
    }

    index++;
    int nine = 1;
    int ul = 0;
    while (index < s.size() && s[index] != ')') {
        ul *= 10;
        ul += (s[index] - '0');
        nine *= 10;
        ++index;
    }
    if (index == s.size() - 1) {
        b = (nine - 1) * ten;
        a = pi * ten * (nine - 1) + lim * (nine - 1) + ul;
        return;
    }
}

bool isRationalEqual(string s, string t) {
    int sa;
    int sb;
    int ta;
    int tb;
    parse(s, sa, sb);
    parse(t, ta, tb);
    return sa * tb == sb * ta;
}

//
int main() {
    printf("%d", isRationalEqual("0.(9)", "1."));
    printf("%d", isRationalEqual("0.12(1)", "0.1(21)"));
    printf("%d", isRationalEqual("0.166(66)", "0.1(6)"));
    return 0;
}
