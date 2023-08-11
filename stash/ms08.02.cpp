#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;
// struct Dir {
//     bool left{false};
//     bool top{false};

//     bool valid() const { return left || top; }
// };
vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int r = obstacleGrid.size();
    int c = obstacleGrid[0].size();
    vector<vector<bool>> dp(r, vector<bool>(c, false));
    dp[0][0] = true;
    // 第一行
    for (int i = 1; i < c; i++) dp[0][i] = obstacleGrid[0][i] == 0 && dp[0][i - 1];
    for (int i = 1; i < r; i++) dp[i][0] = obstacleGrid[i][0] == 0 && dp[i - 1][0];
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            dp[i][j] = obstacleGrid[i][j] == 0 && (dp[i - 1][j] || dp[i][j - 1]);
        }
    }

    vector<int> cur{r - 1, c - 1};
    vector<vector<int>> res;
    while (cur[0] != 0 || cur[1] != 0) {
        res.push_back(cur);
        int x = cur[0];
        int y = cur[1];

        if (x > 0 && dp[x - 1][y]) {
            cur[0]--;
            continue;
        }
        if (y > 0 && dp[x][y - 1]) {
            cur[1]--;
            continue;
        }
    }
    res.push_back({0, 0});
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<vector<int>> v{
        {0, 0, 1, 0},  // x
        {1, 0, 0, 1},  //
        {0, 0, 1, 0},  //
        {0, 0, 0, 0}   //
    };

    dbg(pathWithObstacles(v));
    return 0;
}
