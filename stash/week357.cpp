#include <stdio.h>

#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

string finalString(string s) {
    std::string res;
    for (auto i : s) {
        if (i == 'i') {
            std::reverse(res.begin(), res.end());
        } else {
            res += i;
        }
    }
    return res;
    ;
}

bool split(vector<int>& nums, int sum, int b, int e, int m) {
    if (b >= e) return true;
    if (sum < m) return false;
    if (nums[b] < nums[e]) {
        return split(nums, sum - nums[b], b + 1, e, m);
    } else if (nums[b] > nums[e]) {
        return split(nums, sum - nums[e], b, e - 1, m);
    } else {
        return split(nums, sum - nums[b], b + 1, e, m) || split(nums, sum - nums[e], b, e - 1, m);
    }
}

bool canSplitArray(vector<int>& nums, int m) {
    int begin = 0;
    int end = nums.size() - 1;
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    return split(nums, sum, begin, end, m);
}

int main() {
    std::vector<int> v{4, 1, 2, 3, 4};

    // 4 1 2 |  3 4
    // 4 1 | 2 | 4 | 3
    // 4| 1 |2 | 4| 3
    dbg(canSplitArray(v, 6));
}