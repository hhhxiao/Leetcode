#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(const string &text1, const string &text2) {
    std::vector<std::vector<int>> dp(text1.size() + 1,
                                     vector<int>(text2.size() + 1, 0));
    for (int i = 1; i < text1.size() + 1; i++) {
        for (int j = 1; j < text2.size() + 1; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[text1.size()][text2.size()];
}
int main(int argc, char const *argv[]) { return 0; }