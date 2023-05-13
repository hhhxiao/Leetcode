#include <stdint.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "dbg.h"

long long smallestNumber(long long num) {
    if (num == 0) return 0;
    bool is_neg = false;
    if (num < 0) {
        num = -num;
        is_neg = true;
    }
    std::vector<int> v;
    int ctr_zero = 0;
    while (num > 0) {
        int n = num % 10;
        if (n == 0) {
            ctr_zero++;
        } else {
            v.push_back(num % 10);
        }
        num /= 10;
    }
    std::sort(v.begin(), v.end());
    if (!is_neg) {
        int64_t init = v[0];
        for (int i = 0; i < ctr_zero; i++) {
            init *= 10;
        }
        for (int i = 1; i < v.size(); i++) {
            init *= 10;
            init += v[i];
        }
        return init;
    } else {
        int64_t init = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            init *= 10;
            init += v[i];
        }
        for (int i = 0; i <= ctr_zero; i++) {
            init *= 10;
        }
        return -init;
    }
}
int main() {
    dbg(smallestNumber(-120003012));
    return 0;
}