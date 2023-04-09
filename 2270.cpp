#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "dbg.h"

using namespace std;
int waysToSplitArray(vector<int>& nums) {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    int c = 0;
    int res = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        c += nums[i];
        if (c * 2 >= sum) {
            res++;
        }
    }
    return res;
}

int main() {
    std::vector<int> s{10, 4, -8, 7};
    dbg(waysToSplitArray(s));
    return 0;
}