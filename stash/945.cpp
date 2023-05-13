#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "dbg.h"

#ifndef dbg
#define dbg(x, ...)
#endif

using namespace std;
int minIncrementForUnique(vector<int>& nums) {
    if (nums.empty()) return 0;
    auto max = *std::max_element(nums.begin(), nums.end());

    const auto s = max * 2 + 2;

    std::vector<int> buckets(max * 2 + 2, 0);
    // dbg(max);
    for (auto i : nums) buckets[i]++;

    // // find first none empty
    int p = 0;
    while (p < s && buckets[p] <= 1) p++;
    // // find first empty
    int empty = p;
    while (empty < s && buckets[empty] > 0) empty++;
    dbg(p, empty);

    int res = 0;
    // 双指针
    while (p <= max) {
        // 超过一个
        if (buckets[p] > 1) {
            printf("move %d to %d\n", p, empty);
            // empty不能比p小
            while ((empty < s && buckets[empty] > 0) || empty < p) empty++;

            res += (empty - p);
            // 填充
            buckets[empty] = 1;
            buckets[p]--;
            // 移动到下一个空闲位置
            while (empty < s && buckets[empty] > 0) empty++;
        } else if (buckets[p] <= 1) {
            while (p < s && buckets[p] <= 1) p++;
        }
    }
    return res;
}

int main() {
    std::vector<int> v{14, 4, 5, 14, 13, 14, 10, 17, 2, 12, 2, 14, 7, 13, 14, 13, 4, 16, 4, 10};
    dbg(minIncrementForUnique(v));
    std::sort(v.begin(), v.end());
    dbg(v);
    return 0;
}
