#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

void printTree(const std::string &prefix, const TreeNode *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "`--");
        std::cout << node->val << std::endl;
        printTree(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printTree(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

void printTree(const TreeNode *node) { printTree("", node, false); }
