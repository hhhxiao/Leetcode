#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
    std::vector<int> res(n + 1, -1);
    std::unordered_map<int, std::vector<int>> g;
    for (int i = 0; i < paths.size(); i++) {
        g[paths[i][0]].push_back(paths[i][1]);
        g[paths[i][1]].push_back(paths[i][0]);
    }

    std::queue<int> q;
    int flags[5] = {0, 0, 0, 0, 0};
    q.push(g.begin()->first);
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        auto iter = g.find(f);
        if (iter != g.end()) {
            auto& vec = iter->second;
            for (int i = 0; i < 5; i++) flags[i] = 0;
            for (int i = 0; i < vec.size(); i++) {
                int node = vec[i];
                if (res[node] == -1) {
                    q.push(node);
                } else {
                    flags[res[node]] = 1;
                }
            }

            int color = 1;
            while (flags[color] == 1) ++color;
            res[f] = color;
        }
    }
    return res;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 2}, {1, 3}, {2, 3}};
    gardenNoAdj(3, v);
}