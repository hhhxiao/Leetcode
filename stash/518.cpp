#include <vector>

#include "a.h"

using namespace std;
int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
    // dp[i][am]  =     //    dp[i-1][am] 没有coins[i]的情况 + dp[i][am - coins[i]] //至少放了一个coins[i]的情况
    // dp[i][a] = dp[i-1][j]  +dp[i][j - coins[i]]

    for (int j = 0; j <= amount; j++) {
        dp[0][j] = j % coins[0] == 0 ? 1 : 0;
    }
    for (int i = 0; i < coins.size(); i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j <= amount; j++) {
        for (int i = 1; i < coins.size(); i++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i]) dp[i][j] += dp[i][j - coins[i]];
        }
    }

    return dp[coins.size() - 1][amount];
}
int main() {
    vector<int> x{1, 2, 5};
    dbg(change(20, x));
    return 0;
}