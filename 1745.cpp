#include <string>

#include "dbg.h"

using namespace std;

std::unordered_map<int, bool> cache;

bool is(const std::string& s, int b, int e) {
    auto idx = b * 10000 + e;
    if (cache.count(idx)) {
        return cache[idx];
    }

    int len = (e - b);
    if (len == 0) return false;
    if (len == 1) return true;
    for (int i = 0; i <= len / 2; i++) {
        if (s[b + i] != s[e - i - 1]) {
            cache[idx] = false;

            return false;
        }
    }
    cache[idx] = true;
    return true;
}

bool find(const string& s, int start, int part) {
    if (start >= s.size()) return false;
    if (part == 1) {
        return is(s, start, s.size());
    }

    int p = start + 1;
    while (p < s.size()) {
        if (s[p - 1] == s[start] && is(s, start, p) && find(s, p, part - 1)) {
            return true;
        }
        p++;
    }

    return false;
}

bool checkPartitioning(string s) { return find(s, 0, 3); }

int main() {
    dbg(checkPartitioning(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    return 0;
}