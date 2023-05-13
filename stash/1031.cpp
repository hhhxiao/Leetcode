#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#include "dbg.h"

std::pair<std::vector<int>, std::vector<int>> cacheMax(std::vector<int>& nums, int len) {
    std::vector<int> fmax(nums.size(), -1);
    std::vector<int> fleft(nums.size(), -1);

    int f_sum = 0;

    for (int i = 0; i < len; i++) {
        f_sum += nums[i];
        fmax[len - 1] = f_sum;
        fleft[len - 1] = f_sum;
    }

    int max = f_sum;
    for (int i = len; i < nums.size(); i++) {
        f_sum = f_sum + nums[i] - nums[i - len];
        if (f_sum > max) {
            fmax[i] = f_sum;
            max = f_sum;
        } else {
            fmax[i] = fmax[i - 1];
        }
        fleft[i] = f_sum;
    }
    return {fmax, fleft};
}

// Res(i)表示 从子数据[0,i)中找到的最大值，于是有
int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    // 记录从[0,到i]的最长子数组的值
    auto f = cacheMax(nums, firstLen);  // max_f[i] 表示区间[0,i]之内的最大值

    auto s = cacheMax(nums, secondLen);  // 同上
    auto& FM = f.first;
    auto& FL = f.second;
    auto& SM = s.first;
    auto& SL = s.second;
    // 开始dp
    // 转移方程: Res([0,i]) = {max(Res[0,i-1], F在最右边 +  最大子数组T(F) + V[S], 最大子数组T(S) + V[F])
    // Res([0,i]) = max(Res[0,i-1],FL[i] + SM[i-len(f)], SL[i] + FM[i-len(s)])
    std::vector<int> res(nums.size(), -1);
    int begin = firstLen + secondLen - 1;
    for (int i = begin; i < nums.size(); i++) {
        int m = std::max(FL[i] + SM[i - firstLen], SL[i] + FM[i - secondLen]);
        res[i] = std::max((int)m, (int)res[i - 1]);
    }
    return res.back();
}

int main() {
    std::vector<int> s{0, 6, 5, 2, 2, 5, 1, 9, 4};
    dbg(maxSumTwoNoOverlap(s, 1, 2));
    return 0;
}