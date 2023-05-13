#include <vector>

#include "dbg.h"

int translateNum(int num) {
    if (num < 10) return 1;
    std::vector<int> v;
    while (num > 0) {
        v.push_back(num % 10);
        num /= 10;
    }
    dbg(v);

    std::vector<int> dp(v.size(), 0);
    dp[0] = 1;
    dp[1] = 1 + ((v[1] * 10 + v[0] <= 25 && v[1] != 0) ? 1 : 0);
    dbg(dp);
    for (int i = 2; i < v.size(); i++) {
        dp[i] = dp[i - 1];
        if (v[i] * 10 + v[i - 1] <= 25 && v[i] != 0) {
            dp[i] += dp[i - 2];
        }
    }
    dbg(dp);
    return dp.back();
}

int main(int argc, char const *argv[]) {
    translateNum(506);
    return 0;
}
