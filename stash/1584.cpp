#include <map>
#include <set>
#include <vector>

using namespace std;

std::vector<int> fa;
void initdsu() {
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

int minCostConnectPoints(vector<vector<int>>& points) {
    fa = std::vector<int>(0, points.size());
    initdsu();
    typedef std::pair<int, int> edge_t;
    std::map<int, std::vector<edge_t>> conns;
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int dis = abs(points[i][0] - points[j][0]) +
                      abs(points[i][1] - points[j][1]);
            conns[dis].push_back({i, j});
        }
    }
    int edge = 0;
    int sum = 0;
    while (edge < points.size() - 1) {
        auto f = conns.begin();
        auto back = f->second.back();
        int x1 = find(back.first);
        int x2 = find(back.second);
        if (x1 != x2) {
            edge--;
            fa[x1] = x2;
            sum += f->first;
        }

        f->second.pop_back();
        if (f->second.empty()) {
            conns.erase(f);
        }
    }
    return sum;
}
