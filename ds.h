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
void printBT(const std::string &prefix, const TreeNode *node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├─(<)──" : "└─(>)──");
        // print the value of the node
        std::cout << node->val << std::endl;
        printBT(prefix + (isLeft ? "│           " : "            "), node->left,
                true);
        printBT(prefix + (isLeft ? "│           " : "            "),
                node->right, false);
    }
}