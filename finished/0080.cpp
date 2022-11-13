#include <iostream>

#include "dbg.h"

using namespace std;

int removeDuplicates(vector<int>& nums) {
    const auto sz = nums.size();
    if (sz <= 1) return sz;
    int counter = 1;
    int len = 1;
    int last = nums[0];
    for (int i = 1; i < sz; i++) {
        // 1 2 2 2
        if (nums[i] == last) {
            counter++;
            if (counter == 2) {
                nums[len] = nums[i];
                ++len;
            }
        } else {
            counter = 1;
            nums[len] = nums[i];
            last = nums[len];
            ++len;
        }
        dbg(nums, counter, last, len);
    }
    return len;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    removeDuplicates(v);
    return 0;
}
