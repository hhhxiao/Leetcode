#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
#ifndef dbg
#define dbg(x)
#endif
bool is(const std::string& s) {
    dbg(s.c_str());
    const auto sz = s.size();
    for (int i = 0; i < sz / 2; i++) {
        if (s[i] != s[sz - 1 - i]) return false;
    }
    return true;
}

bool check(const std::string& a, const std::string& b) {
    auto s = 0;
    auto e = b.size() - 1;
    while (a[s] == b[e] && s < e) {
        s++;
        e--;
    }

    // s->[?]

    // a: abx?__
    // b: ___?xba
    // a: abxy?___
    // b: ___?yxba
    if (s >= e) return true;

    // a: abxy?________
    // b: ________?yxba

    // auto n = b.substr(s, b.size() - s + 1);

    return is(b.substr(s, b.size() - s * 2)) || is(a.substr(s, a.size() - s * 2));
}

bool checkPalindromeFormation(string a, string b) {
    dbg(a.size());
    return check(a, b) || check(b, a);
}

int main() {
    dbg(checkPalindromeFormation("aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd",  //
                                 "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea"));
    return 0;
}