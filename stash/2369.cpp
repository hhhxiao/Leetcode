#include <vector>
using namespace std;
bool validPartition(vector<int>& nums) {
    std::vector<bool> dp(nums.size(), 0);
    dp[1] = nums[0] == nums[1];
    dp[2] = (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]) || (nums[0] == nums[1] && nums[1] == nums[2]);
    for (int i = 3; i < nums.size(); i++) {
        dp[i] = (dp[i - 3] && ((nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i]) ||
                               (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]))) ||
                (dp[i - 2] && (nums[i - 1] == nums[i]));
    }
    return dp.back();
}
