#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

#include "dbg.h"
#include "io/io.h"

using namespace std;

void bfs(int start, vector<int>& vis, unordered_map<int, set<int>>& g, vector<vector<int>>& cache, vector<int>& path) {
    vis[start] = 1;
    for (auto& p : path) {
        cache[p][start] = 1;
    }
    auto& ns = g[start];
    path.push_back(start);
    for (auto n : ns) {
        if (vis[n] == 0) bfs(n, vis, g, cache, path);
    }
    path.pop_back();
}

void query(int start, int num, unordered_map<int, std::set<int>>& g, vector<vector<int>>& cache) {
    std::vector<int> visit(num, 0);
    std::vector<int> path;
    bfs(start, visit, g, cache, path);
    //
    for (int i = 0; i < num; i++) {
        if (cache[start][i] != 1) cache[start][i] = 0;
    }
}
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    unordered_map<int, std::set<int>> g;
    for (auto& p : prerequisites) g[p[0]].insert(p[1]);

    vector<bool> rs;
    vector<vector<int>> cache(numCourses, std::vector<int>(numCourses, -1));
    // dbg(g);

    for (auto& q : queries) {
        if (cache[q[0]][q[1]] == -1) {
            query(q[0], numCourses, g, cache);
        }
        rs.push_back(cache[q[0]][q[1]] == 1);
    }

    return rs;
}

int main() {
    vector<vector<int>> v{
        {0, 1},
        {1, 3},
        {2, 3},
        {0, 2},
    };

    vector<vector<int>> q{{0, 3}, {2, 1}, {3, 1}};
    dbg(checkIfPrerequisite(4, v, q));
    return 0;
}