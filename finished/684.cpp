
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int findGrand(const std::vector<int>& dsu, int x) {
    if (dsu[x] == x) return x;
    return findGrand(dsu, dsu[x]);
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    std::vector<int> dsu(edges.size() + 1, 1);
    for (int i = 0; i < dsu.size(); i++) {
        dsu[i] = i;
    }
    for (int i = 0; i < edges.size(); i++) {
        auto& edge = edges[i];
        int g1 = findGrand(dsu, edge[0]);
        int g2 = findGrand(dsu, edge[1]);
        if (g1 == g2) {
            return edge;
        } else {
            dsu[g1] = g2;
        }
    }

    return {-1, -1};
}