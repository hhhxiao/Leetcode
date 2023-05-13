#include <vector>

#include "template/tree.h"
using namespace std;

TreeNode* build(vector<int>& pre, int ps, int pe, std::vector<int>& ino, int is, int ie) {
    if (ps >= pe || is >= ie) return nullptr;
    TreeNode* node = new TreeNode(pre[ps]);

    int i = is;
    while (i < ie && ino[i] != pre[ps]) i++;
    if (i == ie) {
        printf("Error!!\n");
    }
    // printf("%d:\n", pre[ps]);
    // printf("  Left  ==> P: [%d ~ %d)   I: [%d ~ %d)\n", ps + 1, ps + i - is + 1, is, i);
    // printf("  Right ==> P: [%d ~ %d)   I: [%d ~ %d)\n", ps + i - is + 1, pe, i + 1, ie);

    node->left = build(pre, ps + 1, i - is + ps + 1, ino, is, i);
    node->right = build(pre, ps + i - is + 1, pe, ino, i + 1, ie);
    return node;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

int main() {
    std::vector<int> p{3, 1, 4, 6, 2};
    std::vector<int> i{4, 1, 6, 3, 2};
    auto* tree = buildTree(p, i);
    printTree(tree);
    return 0;
}