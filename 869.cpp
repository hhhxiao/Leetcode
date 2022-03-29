#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#include "dbg.h"

bool reorderedPowerOf2(int n) {
    static std::unordered_set<std::string> arr;
    if (arr.empty()) {
        int res = 1;
        while (res <= 1000000000) {
            auto str = std::to_string(res);
            std::sort(str.begin(), str.end());
            arr.insert(str);
            res <<= 1;
        }
    }

    auto t = std::to_string(n);
    std::sort(t.begin(), t.end());
    return arr.count(t);
}

int main() {
    reorderedPowerOf2(12);
    return 0;
}