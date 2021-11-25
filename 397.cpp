#include <iostream>
#include <unordered_map>

#include "dbg.h"

int min(int a, int b) { return a > b ? b : a; }

int minTime(int n, std::unordered_map<int, int> &cache) {
    int ori = n;
    int idx = 0;
    while (n % 2 == 0) {
        idx++;
        n /= 2;
    }
    if (n == 1) return idx;
    auto iter = cache.find(n);
    if (iter == cache.end()) {
        auto r = 1 + min(minTime(n - 1, cache), minTime(n + 1, cache));
        cache[n] = r;
        r += idx;
        return r;
    } else {
        return iter->second + idx;
    }
}
int integerReplacement(int n) {
    std::unordered_map<int, int> cache;
    return minTime(n, cache);
}

int main(int argc, char const *argv[]) {
    dbg(integerReplacement(3335));
    return 0;
}
