#include <iostream>
#include <vector>

void simple_array_dp() {
    std::vector<int> nums;
    std::vector<int> dp(nums.size(), 0);
    for (int len = 1; len <= nums.size(); len++) {
        printf("Current len is %d\n", len);
        for (int start = 0; start <= nums.size() - len; start++) {
            printf("Proecss slice num[%d %d]\n", start, start + len - 1);
        }
    }
}
