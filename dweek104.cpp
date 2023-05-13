#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "dbg.h"
using namespace std;

int matrixSum(vector<vector<int>>& nums) {
    for (auto& line : nums) {
        std::sort(line.begin(), line.end());
    }

    // 找每一列最大值

    int res = 0;
    for (int i = 0; i < nums[0].size(); i++) {
        int m = INT32_MIN;
        for (int j = 0; i < nums.size(); j++) {
            if (nums[j][i] > m) m = nums[j][i];
        }
        res += m;
    }
    return res;
}

using namespace std;

long long maximumOr(vector<int>& nums, int k) {
    std::vector<std::vector<uint64_t>> dp(nums.size(), std::vector<uint64_t>(k + 1, 0));
    dp[0][0] = nums[0];
    // 第一列

    for (int index = 1; index < nums.size(); index++) {
        dp[index][0] = dp[index - 1][0] | nums[index];
    }
    // 第一行

    for (int t = 1; t <= k; t++) {
        dp[0][t] = dp[0][0] << t;
    }

    for (int index = 1; index < nums.size(); index++) {
        //[0,index)共有index + 1个数字
        for (int t = 1; t <= k; t++) {
            uint64_t m = 0;
            for (int self = 0; self <= t; self++) {
                // 当前数字self次数 之前的数字k -self次数
                uint64_t v = (nums[index] << self) | dp[index - 1][t - self];
                if (m < v) m = v;
            }

            dp[index][t] = std::max(m, dp[index][t - 1]);
        }
    }

    return dp[nums.size() - 1][k];
}
int sumOfPower(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    const uint64_t M = 1e9 + 7;
    uint64_t tail = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        tail += ((uint64_t)nums[i]) << (nums.size() - 2 - i);
    }

    uint64_t res = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        uint64_t t = nums[i];
        res += ((t * t) % M) * ((tail + t) % M);
        res %= M;

        if (i - 1 > 0) tail = (tail - (uint64_t)nums[i - 1]) >> 1;
        // 计算尾
    }

    return res % M;
}

int main() {
    std::vector<int> v{1, 2, 4};
    dbg(sumOfPower(v));
    return 0;
}