
#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <vector>

#include "a.h"

using namespace std;

long long minCost(vector<int>& nums, vector<int>& cost) {
    vector<pair<int64_t, int64_t>> v;
    for (int i = 0; i < nums.size(); i++) v.emplace_back(nums[i], cost[i]);
    sort(v.begin(), v.end(),
         [](const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) { return a.first < b.first; });
    vector<int64_t> pfNC, pfC;
    auto sumNC = 0ll;
    auto sumC = 0ll;
    for (int i = 0; i < v.size(); i++) {
        sumC += v[i].second;
        sumNC += v[i].first * v[i].second;
        pfC.push_back(sumC);
        pfNC.push_back(sumNC);
    }
    int64_t res = INT64_MAX;
    for (int i = 0; i < v.size(); i++) {
        // 全部变得和v[i]一样
        // 数值数组计为N,cost数据计为C
        // X = N[i]
        // S1 = sum((X - N[j]) * C[j]) for j in [0,i-1]
        //    = X * (C[0] + C[1] + ....  +C[i-1] + C[i]) - (N[0] * C[0] + N[1] * C[1] + ... + N[i]  * C[i])
        auto s1 = v[i].first * pfC[i] - pfNC[i];
        auto s2 = (pfNC.back() - pfNC[i]) - v[i].first * (pfC.back() - pfC[i]);
        // printf("%lld -> %lld = (%lld + %lld)\n", v[i].first, s1 + s2, s1, s2);
        res = std::min(res, s1 + s2);

        // S2 = sum((N[j] - X) * C[j]) for j in [i+1,v.size()-1]
        //    = (N[i+1]C[i+1] + N[j+2]C[i+2]++...)  - X*(C[i+1] + C[i+2]+ ...)
    }

    return res;
}

int main() {
    std::vector<int> cost{1, 2};
    std::vector<int> nums{1, 2};
    dbg(minCost(nums, cost));

    return 0;
}