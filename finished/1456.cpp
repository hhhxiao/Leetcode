#include <iostream>

#include "dbg.h"

using namespace std;

bool valid(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int maxVowels(const string &s, int k) {
    int begin = 0;
    int end = begin;
    int index = 0;
    int count = 0;
    while (end < s.size() && index < k) {
        if (valid(s[end])) {
            count++;
        }
        ++index;
        ++end;
    }
    if (end == s.size()) {
        return count;
    }
    dbg(begin, end, count);

    int max = count;
    for (int i = 0; i < s.size() - k; i++) {
        if (valid(s[begin])) count--;
        if (valid(s[end])) count++;
        if (max < count) max = count;
        ++begin;
        ++end;
    }

    return max;
}

int main(int argc, char const *argv[]) {
    dbg(maxVowels("ab", 3));
    return 0;
}
