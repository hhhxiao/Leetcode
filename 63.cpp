#include <type_traits>
#include <vector>

#include "a.h"
#include "template/io.h"

using namespace std;
using ll = long long;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int r = obstacleGrid.size();
    int c = obstacleGrid[0].size();
    std::vector<vector<ll>> dp(r, std::vector<ll>(c, 0ll));
    dp[0][0] = obstacleGrid[i][j] == 0;
    for (int i = 1; i < r; i++) {
        dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
    }
    for (int i = 1; i < c; i++) {
        dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
    }

    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = obstacleGrid[i][j] == 0 ? dp[i - 1][j] + dp[i][j - 1] : 0;
        }
    }
    // dbg(dp);

    return dp.back().back();
}

int main() {
    auto m = read_matrix<int>("input.txt", 4, 4);

    dbg(uniquePathsWithObstacles(m));
    return 0;
}
