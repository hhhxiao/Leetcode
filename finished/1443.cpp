
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

int path(const std::vector<int>& tree, int node, const std::vector<bool>& hasApple) {
    if (tree[node * 2] == -1 && tree[node * 2 + 1] == -1) {  //叶子节点
        //有苹果就是2
        auto total = hasApple[node] ? 2 : 0;
        printf("%d --> %d\n", node, total);
        return total;
    } else {
        //左边节点，如果是空的直接就0，不是空的就算一下
        auto left = tree[node * 2] == -1 ? 0 : path(tree, tree[node * 2], hasApple);
        auto right = tree[node * 2 + 1] == -1 ? 0 : path(tree, tree[node * 2 + 1], hasApple);
        auto total = left + right;
        if (total > 0) {  //子树上有果子
            total += 2;
        } else if (hasApple[node]) {
            //子树上没有自己有
            total = 2;
        } else {
            //整个树上没果子
            total = 0;
        }
        printf("%d --> %d\n", node, total);
        return total;
    }
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    std::vector<int> tree(2 * n + 1, -1);
    for (int i = 0; i < edges.size(); i++) {
        auto node = edges[i][0];
        if (tree[node * 2] == -1) {
            tree[node * 2] = edges[i][1];
        } else {
            tree[node * 2 + 1] = edges[i][1];
        }
    }
    auto r = path(tree, 0, hasApple));
    return max(0, r - 2);
}

int main() {
    // 8
    //[[0,1],[1,2],[2,3],[1,4],[2,5],[2,6],[4,7]]
    //[true,true,false,true,false,true,true,false]

    std::vector<vector<int>> v{{0, 1}, {0, 2}, {2, 3}, {1, 4}, {2, 5}, {2, 6}, {4, 7}};
    std::vector<bool> hasApple = {true, true, false, true, false, true, true, false};
    minTime(7, v, hasApple);
    return 0;
}
