#include <vector>

struct UnionSet {
    std::vector<int> fa;
    UnionSet(int n) {
        fa = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
};
