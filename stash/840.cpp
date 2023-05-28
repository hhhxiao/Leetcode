
#include <vector>

#include "io.h"

using namespace std;

int is(int r, int c, const vector<vector<int>>& g) {
    int row = g.size();
    int col = g[0].size();
    if (r + 2 >= row || c + 2 >= col) return 0;

    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < 3; i++) {
        s1 += g[r + i][c + i];
        s2 += g[r + i][c + 2 - i];
    }
    if (s1 != s2) {
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        int r_sum = g[r + i][c] + g[r + i][c + 1] + g[r + i][c + 2];
        int c_sum = g[r][c + i] + g[r + 1][c + i] + g[r + 2][c + i];
        if (r_sum != s1 || c_sum != s1) {
            return 0;
        }
    }
    return 1;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            res += is(i, j, g);
        }
    }
    return res;
}
