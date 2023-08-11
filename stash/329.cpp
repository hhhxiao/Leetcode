
#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>

#include "a.h"
#include "template/io.h"

using namespace std;
const int dx[]{1, -1, 0, 0};
const int dy[]{0, 0, 1, -1};

// 从seed开始搜索出一条最长路径

// void bfs(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& visit, pair<int, int> cur,
//          int path, int& ma) {
//     int row = matrix.size();
//     int col = matrix[0].size();
//     printf("[%d, %d] (%d) -> %d\n", cur.first, cur.second, matrix[cur.first][cur.second], path);
//     ma = std::max(path, ma);
//     visit[cur.first][cur.second] = 1;
//     for (int k = 0; k < 4; k++) {
//         int nx = cur.first + dx[k];
//         int ny = cur.second + dy[k];
//         if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] < matrix[cur.first][cur.second] &&
//             !visit[nx][ny]) {
//             bfs(matrix, visit, {nx, ny}, path + 1, ma);
//         }
//     }
//     visit[cur.first][cur.second] = 0;
// }

// int longestIncreasingPath(vector<vector<int>>& matrix) {
//     int row = matrix.size();
//     int col = matrix[0].size();
//     std::vector<pair<int, int>> seeds;
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             int ctr = 0;
//             for (int k = 0; k < 4; k++) {
//                 int nx = i + dx[k];
//                 int ny = j + dy[k];
//                 if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] > matrix[i][j]) ctr++;
//             }
//             //    printf("[%d %d]-> %d\n", i, j, ctr);
//             if (ctr == 0) {
//                 seeds.emplace_back(i, j);
//             }
//         }
//     }
//     dbg(seeds);
//     int res = 1;
//     for (auto& seed : seeds) {
//         std::vector<std::vector<int>> visit(row, std::vector<int>(col, 0));
//         int path = 0;
//         int ma = 0;
//         bfs(matrix, visit, seed, 1, ma);
//         printf("Max = %d\n", ma);
//         res = std::max(res, ma);
//         printf("-------------------------------------------\n");
//     }
//     return res;
// }
// int main() {
//     auto m = read_matrix<int>("input.txt", 3, 3);
//     dbg(longestIncreasingPath(m));
//     return 0;
// }

int path(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& cache, int x, int y) {
    if (cache[x][y] > 0) return cache[x][y];
    // printf("cal: %d %d\n", x, y);
    int row = matrix.size();
    int col = matrix[0].size();

    std::vector<int> cps;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 0 && nx < row && ny >= 0 && ny < col && matrix[nx][ny] < matrix[x][y]) {
            if (cache[nx][ny] > 0) {
                cps.push_back(cache[nx][ny]);
            } else {
                cps.push_back(path(matrix, cache, nx, ny));
            }
        }
    }

    cache[x][y] = cps.empty() ? 1 : 1 + *std::max_element(cps.begin(), cps.end());
    return cache[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int p = -1;
    std::vector<std::vector<int>> cache(row, std::vector<int>(col, -1));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            p = std::max(p, path(matrix, cache, i, j));
        }
    }
    return p;
}

int main() {
    auto m = read_matrix<int>("input.txt", 3, 3);
    dbg(longestIncreasingPath(m));
    return 0;
}
