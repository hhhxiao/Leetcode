#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

std::unordered_map<int, std::unordered_map<int, int>> g;

void bfs(int start, int left, std::vector<int>& v) {
    v[start] = true;
    auto& edges = g[start];
    for (auto& e : edges) {
        if (e.second >= left) {
            printf("[%d -> %d], %d left\n", start, e.first, left);
        } else {
            if (!v[e.first]) {
                printf("[%d -> %d]\n", start, e.first);
                bfs(e.first, left - e.second, v);
            }
        }
    }
}
int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    for (auto& e : edges) {
        g[e[0]][e[1]] = e[2] + 1;
        g[e[1]][e[0]] = e[2] + 1;
    }
    dbg(g);
    std::vector<int> visit(n, 0);
    bfs(0, maxMoves, visit);
    return 0;
}
int main() {
    std::vector<std::vector<int>> v{{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    reachableNodes(v, 12, 3);
    return 0;
}