#include <vector>

#include "dbg.h"
#include "template/tree.h"

using namespace std;

void traverse(TreeNode* root, int depth, vector<vector<int>>& v) {
    if (!root) return;
    // dbg(root->val);
    if (v.size() < depth) v.resize(depth);
    v[depth - 1].push_back(root->val);
    traverse(root->left, depth + 1, v);
    traverse(root->right, depth + 1, v);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> v;
    traverse(root, 1, v);
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 1) {
            for (auto j = 0; j < v[i].size() / 2; j++) {
                std::swap(v[i][j], v[i][v[i].size() - j - 1]);
            }
        }
    }

    // dbg(v);
    return v;
}

int main() {
    auto* n = new TreeNode(1);
    auto* l1 = new TreeNode(2);
    auto* l2 = new TreeNode(3);
    l1->left = new TreeNode(4);
    l1->right = new TreeNode(5);
    l2->right = new TreeNode(7);
    n->left = l1;
    n->right = l2;
    levelOrder(n);
    return 0;
}