#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
int longestSubarray(vector<int>& nums) {
    if (std::all_of(nums.begin(), nums.end(), [](int v) { return v == 1; })) {
        return nums.size() - 1;
    }
    nums.push_back(0);
    int index = 0;
    while (index < nums.size() && nums[index] == 0) ++index;
    if (index == nums.size()) {
        return nums[index - 1];
    }

    std::vector<pair<int, int>> ctr;

    index++;
    int counter = 1;
    int last = 1;
    while (index < nums.size()) {
        int v = nums[index];
        if (v == last) {
            counter++;
        } else {
            ctr.emplace_back(counter, last);
            last = v;
            counter = 1;
        }
        ++index;
    }

    int max = 0;
    for (int i = 0; i < ctr.size(); i++) {
        auto pair = ctr[i];
        if (pair.second == 1) {
            if (max < pair.first) {
                max = pair.first;
            }
        } else if (pair.second == 0) {
            if (pair.first == 1 && i > 0 && i < ctr.size() - 1) {
                auto n = ctr[i - 1].first + ctr[i + 1].first;
                if (max < n) {
                    max = n;
                }
            }
        }
    }
    return max;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1};
    std::cout << longestSubarray(v);
    return 0;
}
