#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int path(const pair<int, int>& start, const pair<int, int>& end, const vector<vector<int>>& forest) {
    int r = forest.size();
    int c = forest[0].size();
    vector<vector<int>> visit(forest.size(), vector<int>(forest[0].size(), 0));
    std::queue<pair<pair<int, int>, int>> q;
    int res = -1;
    q.emplace(start, 0);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        auto x = f.first;
        auto depth = f.second;
        if (x == end) {
            res = depth;
            break;
        }
        visit[x.first][x.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x.first + dx[i];
            int ny = x.second + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && forest[nx][ny] != 0 && !visit[nx][ny]) {
                q.emplace(std::make_pair(nx, ny), depth + 1);
            }
        }
    }
    return res;
}

int cutOffTree(vector<vector<int>>& forest) {
    vector<pair<int, int>> trees;
    int row = forest.size();
    int col = forest[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (forest[i][j] > 1) {
                trees.emplace_back(i, j);
            }
        }
    }
    std::sort(trees.begin(), trees.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return forest[a.first][a.second] < forest[b.first][b.second];
    });

    pair<int, int> cur{0, 0};
    int res = 0;
    for (int i = 0; i < trees.size(); i++) {
        auto next = trees[i];
        auto p = path(cur, next, forest);
        if (p < 0) return -1;
        res += p;
        cur = next;
    }
    return res;
}

int main() { return 0; }
