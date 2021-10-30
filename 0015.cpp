#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3) return {};
    const auto sz = nums.size();
    std::sort(nums.begin(), nums.end());
    if (nums[sz - 1] < 0 || nums[0] > 0) return {};
}
int main(int argc, char const *argv[]) { return 0; }
