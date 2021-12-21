#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 找出能构成三角形的三个点
// x<=y<=z
// [x,y,z] valid <==> x + y > z
int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int count = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            int sum = nums[i] + nums[j];

            auto upper = std::lower_bound(nums.begin() + j, nums.end(), sum);
            auto d = std::distance(nums.begin() + j + 1, upper);
            count += d;
        }
    }

    return count;
}
int main(int argc, char const* argv[]) {
    std::vector<int> v = {2, 2, 3, 4};
    int n = triangleNumber(v);
    printf("n = %d\n", n);
    return 0;
}
