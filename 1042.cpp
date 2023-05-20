#include <vector>
using namespace std;
#include <set>
#include <unordered_map>

#include "dbg.h"

std::unordered_map<int, std::unordered_set<int>> g;
void bfs(std::vector<int>& visit, int i) {
    if (visit[i - 1] > 0) return;
    auto edges = g[i];
    int color[] = {0, 0, 0, 0, 0};
    for (auto v : edges) {
        if (visit[v - 1] > 0) {
            color[visit[v - 1]] = 1;
        }
    }

    int init_color = 1;
    while (init_color <= 4 && color[init_color] > 0) init_color++;
    visit[i - 1] = init_color;
    for (auto next : edges) {
        if (visit[next - 1] == 0) {
            bfs(visit, next);
        }
    }
}
vector<int> gardenNoAdj(int n, vector<vector<int>>& conns) {
    for (int i = 0; i < conns.size(); i++) {
        g[conns[i][0]].insert(conns[i][1]);
        g[conns[i][1]].insert(conns[i][0]);
    }

    std::vector<int> res(n, 0);
    for (int i = 1; i <= n; i++) {
        bfs(res, i);
    }

    return res;
}

int main() {
    vector<vector<int>> v{{4, 1}, {4, 2}, {4, 3}, {2, 5}, {1, 2}, {1, 5}};
    dbg(gardenNoAdj(5, v));
}