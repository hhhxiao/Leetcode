

#include <cstddef>
#include <locale>
#include <type_traits>
#include <unordered_map>

#include "a.h"
#include "template/tree.h"

using namespace std;

int check(const std::unordered_map<int, int>& m) {
    int odd{0};
    for (auto& kv : m) {
        if (kv.second % 2 == 1) odd++;
    }
    return (odd == 0 || odd == 1) ? 1 : 0;
}

void tr(TreeNode* node, std::unordered_map<int, int>& s, int& n) {
    s[node->val]++;
    if (!node->left && !node->right) {
        n += check(s);
    } else {
        if (node->left) tr(node->left, s, n);
        if (node->right) tr(node->right, s, n);
    }

    s[node->val]--;
    if (s[node->val] == 0) s.erase(node->val);
}

int pseudoPalindromicPaths(TreeNode* root) {
    if (!root) return 0;
    std::unordered_map<int, int> s;

    int res{0};

    tr(root, s, res);
    return res;
}

int main() {
    TreeNode* n = new TreeNode(2);
    n->left = new TreeNode(3, new TreeNode(3), new TreeNode(1));
    n->right = new TreeNode(1, nullptr, new TreeNode(1));
    dbg(pseudoPalindromicPaths(n));

    return 0;
}