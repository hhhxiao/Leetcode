#include <iostream>

#include "dbg.h"

using namespace std;

//采用dp进行
// 1 2 3 4 5 2 3 4 3 1

bool valid_1(char c) { return c != '0'; }
bool valid_2(char c1, char c2) {
    if (c1 == '1') {
        return true;
    } else if (c1 == '2' && c2 >= '0' && c2 <= '6') {
        return true;
    }
    return false;
}

int numDecodings(const string &s) {
    if (s.size() == 1) return valid_1(s[0]) ? 1 : 0;
    std::vector<int> dp(s.size(), 0);
    dp[dp.size() - 1] = valid_1(s[s.size() - 1]);

    if (valid_1(s[dp.size() - 2])) {
        dp[dp.size() - 2] += dp[0];
        if (dp[dp.size() - 1] != 0) dp[dp.size() - 2] += 1;
    }
    if (valid_2(s[dp.size() - 2], s[dp.size() - 1])) {
        dp[dp.size() - 2] += 1;
    }

    for (int i = dp.size() - 3; i >= 0; i--) {
        if (valid_1(s[i])) {
            dp[i] += dp[i + 1];
        }
        if (valid_2(s[i], s[i + 1])) {
            dp[i] += dp[i + 2];
        }
        dbg(dp[i]);
        // 1 2
    }
    return dp[0];
}
int main(int argc, char const *argv[]) {
    auto r = numDecodings("12");
    dbg(r);
    return 0;
}
