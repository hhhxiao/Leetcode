#include "dbg.h"
#include "template/tree.h"

void tr(TreeNode* node) {
    if (!node) return;
    if (node->left) {
        auto* n = new TreeNode(-1);
        n->left = node->left;
        node->left = n;
        tr(n->left);
    }
    if (node->right) {
        auto* n = new TreeNode(-1);
        n->right = node->right;
        node->right = n;
        tr(n->right);
    }
}

TreeNode* expandBinaryTree(TreeNode* root) {
    tr(root);
    return root;
}

int main() {
    auto* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    auto t = expandBinaryTree(tree);
    printTree(t);
    return 0;
}
