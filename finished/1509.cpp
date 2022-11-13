#include <algorithm>
#include <vector>

using namespace std;

int minDifference(vector<int>& nums) {
    if (nums.size() <= 4) return 0;
    std::sort(nums.begin(), nums.end());
    auto sz = nums.size();
    auto min = INT_MAX;
    for (int i = 0; i < 4; i++) {
        auto x = nums[sz - 4 + i] - nums[i];
        if (min > x) min = x;
    }
    return min;
}