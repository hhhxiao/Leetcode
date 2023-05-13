#include <unordered_set>
#include <vector>

using namespace std;
std::vector<int> fa;
int find(int x) {
    if (x != fa[x])  // x 不是自身的父亲，即 x 不是该集合的代表
        fa[x] = find(fa[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
    return fa[x];
}
void unionSet(int x, int y) {
    // x 与 y 所在家族合并
    x = find(x);
    y = find(y);
    fa[x] = y;  // 把 x 的祖先变成 y 的祖先的儿子
}
int findCircleNum(vector<vector<int>>& isConnected) {
    fa = std::vector<int>(isConnected.size(), 0);
    for (int i = 0; i < isConnected.size(); i++) {
        fa[i] = i;
    }

    for (int i = 0; i < isConnected.size() - 1; i++) {
        for (int j = i + 1; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1) {
                unionSet(i, j);
            }
        }
    }
    std::unordered_set<int> set;
    for (int i = 0; i < fa.size(); i++) {
        set.insert(fa[i]);
    }
    return set.size();
}