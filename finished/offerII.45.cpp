#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "dbg.h"

// 8798
// 87
using namespace std;
string minNumber(const vector<int>& nums) {
    std::vector<string> strs;
    std::string res;
    for (int i = 0; i < nums.size(); i++) {
        strs.push_back(std::to_string(nums[i]));
    }

    std::sort(strs.begin(), strs.end(),
              [](const std::string& l, const std::string& r) {
                  return l + r < r + l;
              });
    for (auto str : strs) res += str;
    return res;
}

int main(int argc, char const* argv[]) {
    // 120 < 121 < 12 < 126 < 128
    std::vector<int> nums = {12, 121};
    dbg(minNumber(nums));
    return 0;
}
