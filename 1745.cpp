#include <string>

#include "dbg.h"

using namespace std;

bool is(const std::string& s, int b, int e) {
    int len = (e - b);
    if (len == 1) return true;
    for (int i = 0; i <= len / 2; i++) {
        if (s[b + i] == s[e - i - 1]) {
            return true;
        }
    }
    return false;
}

bool find(const string& s, int start, int part) {
    if (start >= s.size()) return false;
    if (part == 1) {
    }
}

bool checkPartitioning(string s) { dbg(1); }
