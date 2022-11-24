#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

std::vector<int> fa;

void init() {
    for (int i = 0; i < fa.size(); i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (x != fa[x]) fa[x] = find(fa[x]);
    return fa[x];
}

//合并
void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    fa[x] = y;
}

long long countPairs(int n, vector<vector<int>> &edges) {
    fa = std::vector<int>(n, 0);
    init();

    for (int i = 0; i < edges.size(); i++) {
        unionSet(edges[i][0], edges[i][1]);
    }
    std::unordered_map<int, int> ma;
    for (int i = 0; i < fa.size(); i++) {
        ma[find(i)]++;
    }

    dbg(ma);
    uint64_t sum = 0;
    uint64_t sum2 = 0;

    for (auto &kv : ma) {
        sum += kv.second;
        sum2 += kv.second * kv.second;
    }

    return (sum * sum - sum2) >> 1;
}

int main() {
    std::vector<std::vector<int>> edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    dbg(countPairs(7, edges));
}

void search(TreeNode *node, int depth, int &max) {
    if (!node) return;
    if (max < depth) max = depth;
    search(node->left, depth + 1, max);
    search(node->right, depth + 1, max);
}

void sum(TreeNode *node, int depth, int max, int &s) {
    if (!node) return;
    if (max == depth) s += node->val;
    sum(node->left, depth + 1, max, s);
    sum(node->right, depth + 1, max, s);
}

int deepestLeavesSum(TreeNode *root) {
    int max_depth = 0;
    search(root, 0, max_depth);

    int s = 0;
    sum(root, 0, max_depth, s);
    // printf("depth is %d s = %d",max_depth,s);
    return s;
}
