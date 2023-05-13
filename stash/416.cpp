#include <vector>
using namespace std;
#include "dbg.h"
#include "template/prints.h"
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if (sum % 2 != 0) return false;
    sum >>= 1;

    //简单检查有无超过一半的
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == sum) return true;
        if (nums[i] > sum) return false;
    }

    std::vector<std::vector<int>> dp(sum + 1, std::vector<int>(nums.size(), 0));
    //初始化最后一列
    int len = nums.size();
    dp[nums[len - 1]][len - 1] = 1;
    //从倒数第二列往第一列dp
    for (int i = len - 2; i >= 0; i--) {  // i是列号
        printf("col = %d\n", i);
        for (int j = 0; j <= sum; j++) {
            printf("row = %d\n", j);
            dp[j][i] = (nums[i] == j) || (nums[i] < j && dp[j - nums[i]][i + 1]) || dp[j][i + 1];
        }
        // if (dp[sum][i]) return true;
    }
    // dbg(dp);
    print_matrix(dp);
    return false;
}

int main() {
    std::vector<int> v{1, 3, 3, 5};
    dbg(canPartition(v));
}
