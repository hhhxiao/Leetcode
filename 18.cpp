#include <errno.h>
#include <stdio.h>

#include <fstream>
#include <ios>
#include <limits>
#include <regex>
#include <vector>

#include "a.h"

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    if (nums.size() < 4) return {};

    std::vector<std::vector<int>> res;
    for (int i = 0; i < nums.size() - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        for (int j = i + 1; j < nums.size() - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }

            // two pointers

            int left = target - nums[i] - nums[j];
            if (left <= nums[j + 1]) continue;

            int begin = j + 1;
            int end = nums.size() - 1;
            while (begin < end) {
                int sum = nums[begin] + nums[end];
                if (sum == left) {
                    // printf("%d %d %d %d\n", nums[i], nums[j], nums[begin], nums[end]);
                    res.push_back({nums[i], nums[j], nums[begin], nums[end]});

                    while (begin < end && nums[begin] == nums[begin + 1]) {
                        begin++;
                    }
                    begin++;
                    while (begin < end && nums[end] == nums[end - 1]) {
                        end--;
                    }
                    end--;

                } else if (sum > left) {
                    end--;
                } else if (sum < left) {
                    begin++;
                }
            }
        }
    }

    return res;
}

int main() {
    std::vector v{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 4, 2};
    dbg(fourSum(v, 8));

    return 0;
}