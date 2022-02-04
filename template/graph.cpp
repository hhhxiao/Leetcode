#include <unordered_map>
#include <unordered_set>
#include <vector>
void conns_to_graph() {
    std::vector<std::vector<int>> conns;
    std::unordered_map<int, std::unordered_set<int>> g;
    for (int i = 0; i < conns.size(); i++) {
        g[conns[i][0]].insert(conns[i][1]);
        g[conns[i][1]].insert(conns[i][0]);
    }
}
