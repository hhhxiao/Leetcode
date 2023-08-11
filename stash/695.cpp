#include <algorithm>

#include "a.h"

using namespace std;

std::vector<int> fa;
void init(int n) {
    fa = std::vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}

// 查询
int find(int x) {
    if (x != fa[x])           // x 不是自身的父亲，即 x 不是该集合的代表
        fa[x] = find(fa[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
    return fa[x];
}

// 合并
void unionSet(int x, int y) {
    // x 与 y 所在家族合并
    x = find(x);
    y = find(y);
    fa[x] = y;  // 把 x 的祖先变成 y 的祖先的儿子
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    init(r * c);
    const int dx[]{0, 0, 1, -1};
    const int dy[]{1, -1, 0, 0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int rx = i + dx[k];
                    int ry = j + dy[k];
                    if (rx >= 0 && rx < r && ry >= 0 && ry < c && grid[rx][ry] == 1) {
                        unionSet(i * c + j, rx * c + ry);
                    }
                }
            }
        }
    }

    std::map<int, int> ctr;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 1) {
                int id = find(i * c + j);
                ctr[id]++;
            }
        }
    }

    return std::max_element(ctr.begin(), ctr.end(),
                            [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
                                return p1.second < p2.second;
                            })
        ->second;
}
