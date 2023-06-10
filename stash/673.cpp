
#include <errno.h>

#include <vector>

#include "a.h"
using namespace std;
int findNumberOfLIS(vector<int>& nums) {
    std::vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
    }
}