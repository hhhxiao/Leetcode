#include <algorithm>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;
int findLengthOfLCIS(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    std::vector<int> diff;
    for (int i = 1; i < nums.size(); i++) {
        diff.push_back(nums[i] - nums[i - 1]);
    }
    dbg(diff);

    int ctr = 0;
    int ma = 0;
    for (auto i : diff) {
        if (i > 0) {
            ctr++;
        } else {
            dbg(ctr);
            ma = std::max(ctr, ma);
            ctr = 0;
        }
    }

    return ma + 1;
}

int main() {
    std::vector<int> v{1, 3, 5, 7};
    dbg(findLengthOfLCIS(v));
    return 0;
}
