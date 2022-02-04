#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;
int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
        return -1;
    }
    std::unordered_map<int, std::vector<int>> graph;

    for (int i = 0; i < connections.size(); i++) {
        auto& conn = connections[i];
        if (conn[0] > conn[1]) {
            std::swap(conn[0], conn[1]);
        }
        graph[conn[0]].push_back(conn[1]);
    }
    std::vector<bool> flags(n, false);

    int index = 0;
    int group = 0;
    while (index < n) {
        // DFS
        std::queue<int> q;
        q.push(index);
        while (!q.empty()) {
            auto top = q.front();
            flags[top] = true;
            q.pop();
            auto iter = graph.find(top);
            if (iter != graph.end()) {
                auto& list = iter->second;
                for (auto& node : list) {
                    if (!flags[node]) {
                        q.push(node);
                    }
                }
            }
        }
        ++group;
        index++;
        while (index < n && flags[index]) ++index;
    }
    printf("groups = %d", group);
    return group - 1;
}
int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> v = {{0, 1}, {1, 3}, {2, 4}};
    makeConnected(6, v);
    return 0;
}
