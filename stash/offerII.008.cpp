#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    if (nums.empty()) return 0;
    std::vector<int> prefix(1, 0);
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefix.push_back(sum);
    }

    int d = INT16_MAX;
    for (int i = 0; i < prefix.size(); i++) {
        auto it = std::lower_bound(prefix.begin() + i, prefix.end(),
                                   target + prefix[i]);

        int distance = it - (prefix.begin() + i);
        if (d > distance) d = distance;
        if (it != prefix.end()) {
            printf("[%d] ~ [%d]\n", prefix[i], *it);
        }
    }
    return d;
}

int main() {
    std::vector<int> v{2, 3, 1, 2, 4, 3};
    minSubArrayLen(7, v);
    return 0;
}
