#include <iostream>
#include <string>

#include "dbg.h"

bool valid(const std::string& s, int b, int e) {
    while (b < e) {
        if (s[b] != s[e]) return false;
        ++b;
        --e;
    }
    return true;
}

bool validPalindrome(const std::string& s) {
    if (s.size() <= 1) return true;
    int b = 0, e = s.size() - 1;
    while (b < e) {
        if (s[b] == s[e]) {
            b++;
            e--;
            continue;
        } else {
            return valid(s, b + 1, e) || valid(s, b, e - 1);
        }
    }

    return true;
}

int main() {
    dbg(valid("aba", 0, 2));
    dbg(valid("a", 0, 0));
    dbg(valid("abba", 0, 3));

    return 0;
}