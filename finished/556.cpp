#include <algorithm>
#include <vector>

#include "dbg.h"

int nextGreaterElement(int n) {
    uint64_t x = n;
    std::vector<int> v;
    while (n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }

    std::reverse(v.begin(), v.end());
    dbg(v);
    std::next_permutation(v.begin(), v.end());
    dbg(v);
    uint64_t res = 0;
    for (int i = 0; i < v.size(); i++) {
        res *= 10;
        res += v[i];
    }

    if (res <= x || res > INT32_MAX) return -1;
    return res;
}

int main() {
    dbg(nextGreaterElement(2147483476));
    return 0;
}