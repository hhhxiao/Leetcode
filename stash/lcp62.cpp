
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "a.h"

using namespace std;
int transportationHub(vector<vector<int>>& path) {
    unordered_set<int> points;
    unordered_map<int, pair<int, int>> io;
    for (auto& edge : path) {
        points.insert(edge[0]);
        points.insert(edge[1]);
        io[edge[0]].first++;
        io[edge[1]].second++;
    }
    auto it = std::find_if(io.begin(), io.end(), [&](const pair<int, pair<int, int>>& p) {
        return p.second.first == 0 && p.second.second == points.size() - 1;
    });
    return it == io.end() ? -1 : it->first;
}

int main() {
    // vector<vector<int>> v{{0, 3}, {1, 0}, {1, 3}, {2, 0}, {3, 0}, {3, 2}};
    // vector<vector<int>> v{{0, 3}, {1, 0}, {1, 3}, {2, 0}, {3, 0}, {3, 2}};
    vector<vector<int>> v{{0, 1}, {0, 3}, {1, 3}, {2, 0}, {2, 3}};
    dbg(transportationHub(v));
    return 0;
}