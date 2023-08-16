#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

int totalSteps(vector<int>& nums) {
    int last = -10000000;
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= last) {
            res.push_back(nums[i]);
            last = nums[i];
        }
    }
    dbg(res);

    return nums.size() - res.size();
}

int main() {
    std::vector i{5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    dbg(totalSteps(i));

    return 0;
}