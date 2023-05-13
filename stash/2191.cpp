
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

int map_num(const std::vector<int>& m, int val) {
    auto str = std::to_string(val);
    dbg(str);
    for (int i = 0; i < str.size(); i++) {
        str[i] = m[str[i] - '0'] + '0';
    }
    dbg(str);
    return strtol(str.c_str(), nullptr, 10);
}
vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]] = map_num(mapping, nums[i]);
    }

    std::sort(nums.begin(), nums.end(),
              [&](int i, int j) { return map[i] < map[j]; });

    dbg(nums);
    return nums;
}

int main() {
    std::vector<int> mapping = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    sortJumbled(mapping, nums);
}