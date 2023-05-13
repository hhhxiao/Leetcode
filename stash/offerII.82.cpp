#include <iostream>

#include "dbg.h"

// dp
/**
 *S(A) = [V union x for x in S(A-V)]
 *
 */
using namespace std;
#include <set>
#include <unordered_map>
#include <vector>

/**
 *S(A) = [V union x for x in S(A-V)]
 *
 */
/**
 * 设{T}为集合, x为t内的一个元素
 *那么S(T,target) = S(T-x,target - x)
    更细致的
    设数据集为C C(0,i)表示[0,i]之间的所有元素
    有:
    S(i,target) = S(i-1,target - C[i])
    dp[target][i] = dp[targe-c[i]][i-1] + C[i]

 */

typedef std::set<std::vector<int>> ResSet;
#include <algorithm>
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<ResSet>> dp(target + 1, std::vector<ResSet>(candidates.size(), ResSet()));
    // 初始化第一列
    //    auto r = *candidates.begin();
    for (int i = 0; i < candidates.size(); i++) {
        auto r = candidates[i];
        if (r <= target) dp[r][i].insert({r});
    }

    for (int t = 0; t <= target; t++) {
        // 一行一行算
        for (int i = 1; i < candidates.size(); i++) {
            for (auto& s : dp[t][i - 1]) {
                dp[t][i].insert(s);
            }

            auto sub = t - candidates[i];
            if (sub < 0) continue;  // < 0 ,无

            // printf("target = %d, i = %d, find sub = %d\n", t, i, sub);
            auto& res = dp[sub][i - 1];
            for (auto& r : res) {
                auto n = r;
                n.push_back(candidates[i]);
                dp[t][i].insert(n);
            }
        }
    }
    auto& res = dp[target][candidates.size() - 1];
    std::vector<std::vector<int>> ret;
    for (auto& r : res) {
        ret.push_back(r);
    }

    return ret;
}

int main() {
    std::vector<int> r{10, 1, 2, 7, 6, 1, 5};
    dbg(combinationSum2(r, 8));
    return 0;
}
