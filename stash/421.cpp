#include <bitset>
#include <vector>

#include "dbg.h"
#include "template/tree.h"

using namespace std;

constexpr auto BIT = 32;

void insert(TreeNode *&node, const std::bitset<BIT> &bits, int pos) {
    if (pos < 0) return;
    if (bits[pos]) {
        if (!node->left) node->left = new TreeNode(-1);
        if (pos == 0) node->left->val = bits.to_ulong();
        insert(node->left, bits, pos - 1);
    } else {
        if (!node->right) node->right = new TreeNode(-1);
        if (pos == 0) node->right->val = bits.to_ulong();
        insert(node->right, bits, pos - 1);
    }
}

int findBest(TreeNode *node, const std::bitset<BIT> &bits, int pos) {
    if (bits[pos]) {  // 右
        if (node->right) return findBest(node->right, bits, pos - 1);
        if (node->left) return findBest(node->left, bits, pos - 1);
        return node->val;
    } else {
        if (node->left) return findBest(node->left, bits, pos - 1);
        if (node->right) return findBest(node->right, bits, pos - 1);
        return node->val;
    }
}

int findMaximumXOR(vector<int> &nums) {
    TreeNode *root = new TreeNode(-1);
    // build tree
    for (auto i : nums) {
        std::bitset<BIT> b(i);
        insert(root, b, BIT - 1);
    }
    int res = -1;
    for (auto i : nums) {
        std::bitset<BIT> b(i);
        res = std::max(res, findBest(root, b, BIT - 1) ^ i);
    }
    return res;
}

int main() {
    std::vector<int> v{4, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    dbg(findMaximumXOR(v));
    return 0;
}