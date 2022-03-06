#include <vector>
std::vector<int> fa;
void init() {
    for (int i = 0; i < fa.size(); i++) {
        fa[i] = i;
    }
}

//查询
int find(int x) {
    if (x != fa[x])  // x 不是自身的父亲，即 x 不是该集合的代表
        fa[x] = find(fa[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
    return fa[x];
}

//合并
void unionSet(int x, int y) {
    // x 与 y 所在家族合并
    x = find(x);
    y = find(y);
    fa[x] = y;  // 把 x 的祖先变成 y 的祖先的儿子
}