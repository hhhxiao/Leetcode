#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;
std::unordered_map<int, std::unordered_set<int>> g;
unordered_map<int, int> bfs(int start, int n, int& res) {
    vector<bool> visit(n, false);
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    int max = -1;
    res = -1;
    std::unordered_map<int, int> trace;
    while (!q.empty()) {
        auto f = q.front();
        if (max < f.second) {
            max = f.second;
            res = f.first;
        }
        q.pop();
        visit[f.first] = true;
        auto& edges = g[f.first];
        for (auto& e : edges) {
            if (!visit[e]) {
                q.emplace(e, f.second + 1);
                trace[e] = f.first;
            }
        }
    }
    return trace;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    for (auto& e : edges) {
        g[e[1]].insert(e[0]);
        g[e[0]].insert(e[1]);
    }
    int far = 0;
    bfs(0, n, far);
    int near = 0;
    auto traces = bfs(far, n, near);
    int cur = near;
    std::vector<int> v;
    v.push_back(cur);
    while (cur != far) {
        cur = traces[cur];
        v.push_back(cur);
    }
    std::vector<int> res(1, v[v.size() / 2]);
    if (v.size() % 2 == 0) res.push_back(v[v.size() / 2 - 1]);
    return res;
}

int main() {
    int n = 1;
    vector<vector<int>> edges{};
    dbg(findMinHeightTrees(n, edges));
    return 0;
}