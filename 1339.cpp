#include <algorithm>
#include <set>

#include "dbg.h"
#include "template/tree.h"

int sumTree(TreeNode* root, std::set<int>& s) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        s.insert(root->val);
        return root->val;
    }
    root->val += sumTree(root->left, s) + sumTree(root->right, s);
    s.insert(root->val);
    return root->val;
}

int maxProduct(TreeNode* root) {
    const int M = 1000000007;

    printTree(root);
    std::set<int> s;
    sumTree(root, s);
    dbg(s);
    printTree(root);

    auto bigger = s.upper_bound(*s.rbegin() / 2);
    printf("bigger is %d", *bigger);

    //第一个
    if (bigger == s.begin()) {
        int x1 = *bigger;
        int x2 = *s.rbegin() - *bigger;
        return ((x1 % M) * (x2 % M)) % M;
    }

    //后面就是两种情况了
    auto less = std::prev(bigger);
    printf("less = %d , bigger = %d\n", *less, *bigger);
    auto r1 = static_cast<uint64_t>(*less) *
              static_cast<uint64_t>(*s.rbegin() - *less);
    auto r2 = static_cast<uint64_t>(*bigger) *
              static_cast<uint64_t>(*s.rbegin() - *bigger);
    return r1 > r2 ? r1 % M : r2 % M;
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
