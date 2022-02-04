#include <vector>
void initDsu() {
    std::vector<int> dsu(10000, 1);
    for (int i = 0; i < dsu.size(); i++) {
        dsu[i] = i;
    }
}
int findGrand(const std::vector<int>& dsu, int x) {
    if (dsu[x] == x) return x;
    return findGrand(dsu, dsu[x]);
}
