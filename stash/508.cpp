#include <map>

#include "template/tree.h"

using namespace std;

#include <unordered_map>
#include <vector>

#include "dbg.h"

int tr(TreeNode* node, std::unordered_map<int, int>& m) {
    if (!node) return 0;
    int res = tr(node->left, m) + tr(node->right, m) + node->val;
    m[res]++;
    return res;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root) return {};
    std::unordered_map<int, int> m;
    tr(root, m);
    std::map<int, std::vector<int>> a;
    for (auto& kv : m) {
        a[kv.second].push_back(kv.first);
    }
    return a.rbegin()->second;
}

int main() {
    auto* root = new TreeNode(2);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    findFrequentTreeSum(root);
    return 0;
}
