#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <type_traits>
#include <vector>

#include "a.h"
using namespace std;

int firstMissingPositive2(vector<int>& nums) {
    constexpr auto N = 500001;
    std::array<bool, N> s;
    std::fill(s.begin(), s.end(), 0);
    for (auto i : nums) {
        if (i >= 0 && i < N) {
            s[i] = true;
        }
    }

    for (int i = 1; i < N; i++) {
        if (s[i]) return i;
    }

    return -1;
}

int firstMissingPositive(vector<int>& nums) {
    std::for_each(nums.begin(), nums.end(), [&](int& n) { n = n > 0 ? n : nums.size() + 2; });
    for (int i = 0; i < nums.size(); i++) {
        auto x = abs(nums[i]);
        if (x >= 1 && x <= nums.size()) {
            nums[x - 1] = -abs(nums[x - 1]);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }
    return nums.size() + 1;
}
int main() {
    vector<int> v{1, 2, 3, 4, 5};
    dbg(firstMissingPositive(v));
    return 0;
}
