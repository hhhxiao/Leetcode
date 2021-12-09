#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return {};
    if (nums.size() == 1) return {1};
    std::vector<int> res(nums.size(), 1);
    int sum = 1;
    int sum2 = 1;
    for (int i = 0; i < nums.size() - 1; i++) {
        sum *= nums[i];
        sum2 *= nums[nums.size() - 1 - i];
        res[nums.size() - i - 2] *= sum2;
        res[i + 1] *= sum;
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {1, 2, 3, 4, 4, 5};
    dbg(productExceptSelf(v));
    return 0;
}
