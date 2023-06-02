#include <vector>
using namespace std;
int maxSum(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int res = INT32_MIN;
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            int v = 0;
            for (int k = 0; k < 3; k++) {
                v += grid[i][j + k] + grid[i + 1][j + k] + grid[i + 2][j + k];
            }
            v -= (grid[i + 1][j] + grid[i + 1][j + 2]);
            res = std::max(v, res);
        }
    }
}
