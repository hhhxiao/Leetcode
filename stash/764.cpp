#include <algorithm>
#include <array>
#include <type_traits>
#include <vector>

#include "a.h"
#include "template/io.h"

using namespace std;

std::vector<std::vector<int>> matrix;
std::vector<std::vector<std::array<int, 4>>> dp;

int search(int dir, int r, int c) {
    if (dp[r][c][dir] != -1) return dp[r][c][dir];
    if (matrix[r][c] == 0) {
        dp[r][c][dir] = 0;
        return 0;
    }

    const int dx[]{-1, 1, 0, 0};
    const int dy[]{0, 0, -1, 1};
    int nr = r + dx[dir];
    int nc = c + dy[dir];
    auto res = (nr >= 0 && nr < matrix.size() && nc >= 0 && nc < matrix.size())
                   ? (matrix[nr][nc] == 0 ? 0 : 1 + search(dir, nr, nc))
                   : 0;
    dp[r][c][dir] = res;
    return res;
}

int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
    matrix = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
    for (auto& cp : mines) {
        mines[cp[0]][cp[1]] = 1;
    }

    // dbg(matrix);

    dp = std::vector<std::vector<std::array<int, 4>>>(
        n, std::vector<std::array<int, 4>>(n, {-1, -1, -1, -1}));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                search(i, j, k);
            }
        }
    }

    int res = 0;
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (matrix[j][k] == 1) {
                int x = 1 + *std::min_element(dp[j][k].begin(), dp[j][k].end());
                res = std::max(x, res);
            }
        }
    }

    return res;
}

int main() {
    matrix = read_matrix<int>("input.txt", 5, 5);
    std::vector<std::vector<int>> x;
    dbg(orderOfLargestPlusSign(5, x));
    return 0;
}