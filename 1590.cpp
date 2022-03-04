#include <cstdio>
#include <vector>

#include "dbg.h"
using namespace std;
// int minSubarray2(vector<int>& nums, int p) {
//     int sum = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         sum += nums[i];
//         sum %= p;
//     }
//     if (sum == 0) return 0;
//     int diff = p - sum;
//     std::vector<int> dp(nums.size(), 0);
//     for (int len = 1; len <= nums.size(); len++) {
//         for (int start = 0; start <= nums.size() - len; start++) {
//             dp[start] += nums[start + len - 1];
//             dp[start] %= p;
//             if (dp[start] == sum) {
//                 return len == nums.size() ? -1 : len;
//             }
//         }
//     }
//     return 0;
// }

int minSubarray(vector<int>& nums, int p) {
    std::vector<int> prefixSum(nums.size() + 1, 0);
    prefixSum[0] = 0;
    prefixSum[1] = nums[0] % p;
    for (int i = 1; i < nums.size(); i++) {
        prefixSum[i + 1] = (prefixSum[i] + nums[i]) % p;
    }
    int remain = prefixSum[prefixSum.size() - 1];
    dbg(prefixSum);
    dbg(remain);
    // x y
    //(y + p - x ) %  p == remain
    // x + remain
    // y - remina + p

    if (remain == 0) return 0;
    return 1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {2, 1, 4, 1};
    minSubarray(v, 5);
    return 0;
}
