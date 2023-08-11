#include <new>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "a.h"
#include "template/io.h"
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

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int r = grid2.size();
    int c = grid2[0].size();
    init(r * c);
    const int dx[]{0, 0, 1, -1};
    const int dy[]{1, -1, 0, 0};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid2[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int rx = i + dx[k];
                    int ry = j + dy[k];
                    if (rx >= 0 && rx < r && ry >= 0 && ry < c && grid2[rx][ry] == 1) {
                        unionSet(i * c + j, rx * c + ry);
                    }
                }
            }
        }
    }

    std::unordered_set<int> all_island;
    std::unordered_set<int> black_list;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid2[i][j] == 1) {
                int id = find(i * c + j);
                all_island.insert(id);
                if (grid1[i][j] == 0) {
                    black_list.insert(id);
                }
            }
        }
    }

    return all_island.size() - black_list.size();
}

int main() {
    // auto m2 = read_matrix<int>("input.txt", 5, 5);
    // auto m1 = m2;
    // m1[0][0] = 0;
    // m1[0][1] = 0;
    // dbg(countSubIslands(m1, m2));

    std::pair<int, int> arr[1]{
        {1, 1},
    };
    dbg(arr);
    return 0;
}
