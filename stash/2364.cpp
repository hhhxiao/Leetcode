#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
long long countBadPairs(const vector<int>& nums) {
    // x[i] - x[j] = i  - j
    // x[i] - i = x[j] - j
    std::unordered_map<int, uint64_t> m;
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i] - i]++;
    }
    dbg(m);
    uint64_t good = 0;
    for (auto kv : m) {
        good += kv.second * (kv.second - 1) / 2;
    }

    uint64_t total = nums.size();
    return total * (total - 1) / 2 - good;
}

int main() {
    dbg(countBadPairs({4, 1, 3, 3}));
    return 0;
}
