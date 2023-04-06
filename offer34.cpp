/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>

#include "template/tree.h"

using namespace std;
class Solution {
   public:
    void tr(TreeNode* node, std::vector<int>& path, int sum, int target, std::vector<std::vector<int>>& res) {
        path.push_back(node->val);
        if ((!node->left) && (!node->right)) {
            if (sum + node->val == target) {
                res.push_back(path);
            }
            path.pop_back();
            return;
        }

        if (node->left) {
            tr(node->left, path, sum + node->val, target, res);
        }

        if (node->right) {
            tr(node->right, path, sum + node->val, target, res);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if (!root) return {};
        std::vector<std::vector<int>> res;
        std::vector<int> path;
        int sum = 0;
        tr(root, path, 0, target, res);
        return res;
    }
};
