
//有向图，不能用并查集，白做了
#include <vector>
using namespace std;
int findGrand(const std::vector<int>& dsu, int x) {
    if (dsu[x] == x) return x;
    return findGrand(dsu, dsu[x]);
}

void merge(std::vector<int>& dsu, int x, int y) {
    x = findGrand(dsu, x);
    y = findGrand(dsu, y);
    dsu[x] = y;
}
bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start,
                           int target) {
    std::vector<int> dsu(n, 1);
    for (int i = 0; i < dsu.size(); i++) {
        dsu[i] = i;
    }

    for (int i = 0; i < graph.size(); i++) {
        merge(dsu, graph[i][0], graph[i][1]);
    }
    return dsu[start] == dsu[target];
}