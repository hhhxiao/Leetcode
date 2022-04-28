#include "dbg.h"
#include "ds.h"

void traverseTree(TreeNode *node, int &last_val, bool &res) {
    if (!node) return;
    traverseTree(node->left, last_val, res);
    dbg(node->val);
    if (node->val > last_val) {
        last_val = node->val;
    } else {
        res = false;
        return;
    }
    traverseTree(node->right, last_val, res);
}

bool isValidBST(TreeNode *root) {
    bool res = true;
    int last_val = INT32_MIN;
    traverseTree(root, last_val, res);
    return res;
}

int main(int argc, char const *argv[]) {
    TreeNode *node = new TreeNode(1, new TreeNode(1), nullptr);
    dbg(isValidBST(node));
    return 0;
}
