#include <iostream>
#include <vector>

#include "dbg.h"
#include "io/io.h"

using namespace std;
vector<int> circularGameLosers(int n, int k) {
    std::vector<int> ctr(n, 0);
    ctr[0] = 1;
    int round = 1;
    int cur = 0;
    do {
        int step = round * k;
        cur = (cur + step) % n;
        ctr[cur]++;
        if (ctr[cur] >= 2) break;
        round++;

    } while (true);

    std::vector<int> res;
    for (int i = 0; i < n; i++) {
        if (ctr[i] == 0) {
            res.push_back(i + 1);
        }
    }

    return res;
}

bool doesValidArrayExist(vector<int>& derived) {
    int r = 0;
    for (int i = 0; i < derived.size(); i++) {
        r ^= derived[i];
    }
    return r == 0;
}

int maxMoves(vector<vector<int>>& grid) {
    int rs = grid.size();
    int cs = grid[0].size();

    vector<vector<int>> dp(rs, vector<int>(cs, 0));
    for (int i = cs - 2; i >= 0; i--) {
        for (int j = 0; j < rs; j++) {
            int cur = grid[j][i];
            int c1 = j > 0 && grid[j - 1][i + 1] > cur ? dp[j - 1][i + 1] + 1 : 0;
            int c2 = grid[j][i + 1] > cur ? dp[j][i + 1] + 1 : 0;
            int c3 = j < rs - 1 && grid[j + 1][i + 1] > cur ? dp[j + 1][i + 1] + 1 : 0;
            dp[j][i] = std::max(std::max(c1, c2), c3);
        }
    }

    // dbg(dp);

    int x = INT32_MIN;
    for (int r = 0; r < rs; r++) {
        if (x < dp[r][0]) x = dp[r][0];
    }
    return x;
}
#include <unordered_map>
#include <unordered_set>

std::vector<int> fa;

void init() {
    for (int i = 0; i < fa.size(); i++) {
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

int countCompleteComponents(int n, vector<vector<int>>& edges) {
    fa = std::vector<int>(n, 0);
    init();
    std::unordered_map<int, int> v;
    for (auto& c : edges) {
        v[c[0]]++;
        v[c[1]]++;
        unionSet(c[0], c[1]);
    }
    dbg(v);

    std::unordered_map<int, std::unordered_set<int>> subs;
    for (int i = 0; i < n; i++) {
        subs[find(i)].insert(i);
    }

    int res = 0;

    for (auto& sub : subs) {
        int cnt = 0;
        for (auto c : sub.second) {
            cnt += v[c];
        }
        // printf("%d --> %d\n", sub.first, cnt);

        if (sub.second.size() * (sub.second.size() - 1) == cnt) {
            res++;
        }
    }
    // dbg(subs);
    // 子图判定

    return res;
}

int main() {
    std::vector<std::vector<int>> v{{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    dbg(countCompleteComponents(6, v));
    return 0;
}