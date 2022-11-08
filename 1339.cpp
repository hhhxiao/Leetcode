#include <algorithm>
#include <set>

#include "dbg.h"
#include "template/tree.h"

int sumTree(TreeNode* root, std::vector<int>& s) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        s.push_back(root->val);
        return root->val;
    }
    root->val += sumTree(root->left, s) + sumTree(root->right, s);
    s.push_back(root->val);
    return root->val;
}

int maxProduct(TreeNode* root) {
    const int M = 1000000007;
    std::vector<int> s;
    sumTree(root, s);

    int max = *std::max_element(s.begin(), s.end());
    dbg(max);
    uint64_t r = 0;

    for (auto& i : s) {
        auto res = (uint64_t)i * (uint64_t)(max - i);
        if (r < res) r = res;
    }
    return r % M;
}
int main() {
    auto* root = new TreeNode(1);
    auto* l = new TreeNode(2);
    auto* r = new TreeNode(3);
    root->left = l;
    root->right = r;
    l->left = new TreeNode(1);
    l->right = new TreeNode(3);
    r->right = new TreeNode(5);
    r->left = new TreeNode(5);
    std::cout << maxProduct(root);
}
