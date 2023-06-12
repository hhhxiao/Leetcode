
#include <stdio.h>

#include <queue>
#include <vector>

#include "a.h"

using namespace std;

int getx(vector<vector<int>>& g, int r, int c) {
    if (c >= g[0].size() || c < 0) return -1;
    if (r >= g.size()) return c;
    if (g[r][c] == 1) {
        if (c + 1 < g[0].size() && g[r][c + 1] == 1) {  // 卡在右边线
            return getx(g, r + 1, c + 1);
        } else {
            return -1;
        }

    } else {
        if (c - 1 >= 0 && g[r][c - 1] == -1) {  // 卡在右边线
            return getx(g, r + 1, c - 1);
        } else {
            return -1;
        }
    }
}

vector<int> findBall(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    std::vector<int> res;
    for (int i = 0; i < c; i++) {
        res.push_back(getx(grid, 0, i));
    }
    return res;
}

int main() {
    vector<vector<int>> x{{1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}};

    dbg(findBall(x));
    return 0;
    //
}