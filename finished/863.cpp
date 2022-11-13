#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "ds.h"

using namespace std;
void traverseTree(TreeNode* node,
                  std::unordered_map<int, std::unordered_set<int>>& graph) {
    if (node->left) {
        graph[node->val].insert(node->left->val);
        graph[node->left->val].insert(node->val);
        traverseTree(node->left, graph);
    }
    if (node->right) {
        graph[node->val].insert(node->right->val);
        graph[node->right->val].insert(node->val);
        traverseTree(node->right, graph);
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (!root) return {};
    std::vector<int> res;
    std::unordered_map<int, std::unordered_set<int>> graph;
    traverseTree(root, graph);
    std::queue<std::pair<int, int>> q;
    std::vector<int> visited(501, 0);
    q.push({target->val, 0});
    while (!q.empty()) {
        auto top = q.front();
        printf("v = %d,d = ", top.first, top.second);
        if (top.second == k) {
            res.push_back(top.second);
        }
        q.pop();
        visited[top.first] = 1;
        auto iter = graph.find(top.first);
        if (iter != graph.end()) {
            for (auto node : iter->second) {
                if (visited[node] == 0) {
                    q.push({node, top.second + 1});
                }
            }
        }
    }
    return res;
}
