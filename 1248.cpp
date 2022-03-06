#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    nums[0] = nums[0] % 2 == 0 ? 0 : 1;
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i - 1] + (nums[i] % 2 == 0 ? 0 : 1);
    }
    // dbg(nums);

    std::unordered_map<int, int> table;
    table[0] = 1;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        auto iter = table.find(nums[i] - k);
        if (iter != table.end()) {
            res += iter->second;
        }
        table[nums[i]]++;
    }
    return res;
}

int main() {
    std::vector<int> v = {1, 2, 3, 3, 4, 1, 2, 3};
    numberOfSubarrays(v, 3);
}
