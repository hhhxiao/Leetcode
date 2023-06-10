#include "a.h"
using namespace std;
int combinationSum4_old(vector<int>& nums, int target) {
    typedef vector<vector<int>> Type;
    vector<vector<Type>> dp(nums.size(), vector<Type>(target + 1, Type{}));
    // dp[i][j]表示子数组nums[0,i] 中总和为j的子数组数量
    // dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i]]
    int d = 0;
    while (nums[0] * d <= target) {
        dp[0][nums[0] * d] = std::vector<std::vector<int>>{vector(d, nums[0])};
        d++;
    }

    for (int i = 0; i < nums.size(); i++) {
        dp[i][0] = {{}};
    }

    // dbg
    for (auto i : dp) {
        dbg(i);
    }
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= target; j++) {
            int d = 0;

            while (j - nums[i] * d >= 0) {
                auto vs = dp[i - 1][j - nums[i] * d];
                for (auto& x : vs) {
                    for (int k = 0; k < d; k++) {
                        x.push_back(nums[i]);
                    }
                    dp[i][j].push_back(x);
                }

                d++;
            }
        }
    }
    auto xs = dp[nums.size() - 1][target];
    return 0;
}

int64_t nChoosek(int64_t n, int64_t k) {
    if (k > n) return 0;
    if (k * 2 > n) k = n - k;
    if (k == 0) return 1;
    int result = n;
    for (int i = 2; i <= k; ++i) {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int combinationSum4(vector<int>& nums, int target) {
    typedef unordered_map<int, int> Type;
    vector<vector<Type>> dp(nums.size(), vector<Type>(target + 1, Type{}));
    // dp[i][j]表示子数组nums[0,i] 中总和为j的子数组数量
    // dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i]]
    int d = 0;
    while (nums[0] * d <= target) {
        dp[0][nums[0] * d] = {{d, 1}};
        //  std::vector<std::vector<int>>{vector(d, nums[0])};
        d++;
    }

    for (int i = 0; i < nums.size(); i++) {
        dp[i][0] = {{0, 1}};
    }

    for (int i = 1; i < nums.size(); i++) {
        for (int j = 1; j <= target; j++) {
            int d = 0;
            while (j - nums[i] * d >= 0) {
                auto& v = dp[i - 1][j - nums[i] * d];
                for (auto& kv : v) {
                    // 有kv->first个元素,向其中插入d个元素
                    if (kv.first > 0) {
                        dp[i][j][kv.first + d] += nChoosek(kv.first + d, d) * kv.second;
                    } else {
                        dp[i][j][d]++;
                    }
                }
                d++;
            }
        }
    }
    auto& xs = dp[nums.size() - 1][target];

    int r = 0;
    for (auto& s : xs) {
        r += s.second;
    }

    return r;
}

int main() {
    vector i{1, 2};
    dbg(combinationSum4(i, 10));
    return 0;
}