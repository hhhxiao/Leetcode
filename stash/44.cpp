#include <stdio.h>

#include <string>
#include <type_traits>

#include "a.h"

using namespace std;

bool match(const std::string& s, int ss, const std::string& p, int ps) {
    if (ss >= s.size() && ps >= p.size()) return true;
    if (ss > s.size() && std::all_of(p.begin() + ps, p.end(), [](char c) { return c == '*'; })) {
        return true;
    }
    if (ss > s.size() || ps > p.size()) return false;

    if (p[ps] == '*') {
        int idx = ss;
        while (idx <= s.size()) {
            if (match(s, idx, p, ps + 1)) return true;
            idx++;
        }
        return false;
    } else {
        if (p[ps] == '?' || p[ps] == s[ss]) return match(s, ss + 1, p, ps + 1);
        return false;
    }
}

bool isMatch(string s, string p) { return match(s, 0, p, 0); }

int main() {
    dbg(isMatch("", "************"));

    return 0;
}
