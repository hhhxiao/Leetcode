#include <algorithm>
#include <vector>

#include "dbg.h"

using namespace std;
vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    std::sort(nums.begin(), nums.end());
    dbg(nums);
    std::vector<long long> prefix;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefix.push_back(sum);
    }
    dbg(prefix);
    std::vector<long long> res;
    for (auto q : queries) {
        auto it = std::lower_bound(nums.begin(), nums.end(), q);
        // 1 3  6  7
        // q = 5, idx->6

        if (it == nums.begin()) {
            res.push_back(sum - q * nums.size());
            continue;
        }

        auto idx = std::distance(nums.begin(), it);
        auto sum_l = prefix[idx - 1];
        auto sum_r = sum - prefix[idx - 1];
        int r = (q * idx) - sum_l + sum_r - (q * (nums.size() - idx));
        res.push_back(r);
    }
    return res;
}

int main() {
    std::vector<int> nums{3, 1, 6, 8};
    std::vector<int> querires{-1, 1, 5, 9, 6};
    dbg(minOperations(nums, querires));
    return 0;
}