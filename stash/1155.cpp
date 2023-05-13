#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
int numRollsToTarget(int d, int f, int target) {
    std::vector<int> dp(target + 1, 0);
    for (int i = 1; i <= f; i++) {
        dp[i] = 1;
    }

    for (int i = 2; i <= d; i++) {
        std::vector<int> current(target + 1, 0);
        //计算i个骰子能丢出来的最大值
        int max_val = min(i * f, target);
        //第i个骰子能丢出来的最小值
        int min_val = i;
        for (int val = min_val; val <= max_val; val++) {
            for (int t = 1; t <= f; t++) {
                //如果当前骰子丢了个t,要达到综合为val,那么剩下的的n-1个骰子就要丢个val-t
                int expect = val - t;
                int i_min = i - 1;
                int i_max = i_min * f;
                if (expect >= i_min && expect <= i_max)
                    current[val] += dp[val - t];
                current[val] %= 1000000007;
            }
        }
        dp = current;
    }
    return dp[target] % 1000000007;
}

int main(int argc, char const *argv[]) {
    dbg(numRollsToTarget(1, 2, 3));
    return 0;
}
