#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    //计算差分序列
    for (int i = 0; i < nums.size() - 1; i++) {
        nums[i] = nums[i + 1] - nums[i];
    }

    nums[nums.size() - 1] = 2000000;
    int count = 0;
    int last = -100000;

    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        int v = nums[i];
        if (last != v) {
            if (count >= 2) {
                res += count * (count - 1) / 2;
            }
            count = 1;
            last = v;
        } else if (last == v) {
            count++;
        }
    }

    return res;
}

main() {
    std::vector<int> v = {1, 2, 3, 4, 6, 8, 9, 10, 10, 10, 10};
    std::cout << numberOfArithmeticSlices(v);
    return 0;
}