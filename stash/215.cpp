#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
int findKthLargest(vector<int>& nums, int k) {
    std::partial_sort(nums.begin(), nums.begin() + k, nums.end(),
                      std::greater<int>());

    dbg(nums);

    return nums[k - 1];
}
