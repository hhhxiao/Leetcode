#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int minPairSum(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int begin = 0, end = nums.size() - 1;
    int max = INT32_MIN;
    while (begin < end) {
        int sum = nums[begin] + nums[end];
        if (max < sum) max = sum;
        begin++;
        end--;
    }
    return max;
}

int main() {}
