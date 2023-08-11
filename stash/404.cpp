#include "a.h"
#include "ds.h"
void traverse(TreeNode* node, int& sum) {
    if (node->left && (!node->left->left) && (!node->left->right)) sum += node->left->val;
    if (node->left) traverse(node->left, sum);
    if (node->right) traverse(node->right, sum);
}

int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    traverse(root, sum);
    return sum;
}
