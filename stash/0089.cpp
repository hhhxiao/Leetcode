#include <bitset>
#include <iostream>

#include "dbg.h"

using namespace std;

uint32_t cover(uint32_t val, int n) {
    int last = val % 2;
    int res = 0;
    val >>= 1;
    for (int i = 1; i < n; i++) {
        int b = val % 2;
        res += (last ^ b) << (i - 1);
        last = b;
        val >>= 1;
    }
    res += last << (n - 1);
    return res;
}

vector<int> grayCode(int n) {
    std::vector<int> res;
    const uint32_t max = 1 << n;
    for (int i = 0; i < max; i++) {
        int r = cover(i, n);
    }
    return res;
}
int main(int argc, char const *argv[]) {
    grayCode(4);
    return 0;
}
