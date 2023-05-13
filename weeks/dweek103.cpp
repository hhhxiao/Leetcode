#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#include "dbg.h"

using namespace std;
int maximizeSum(vector<int>& nums, int k) {
    auto i = *std::max_element(nums.begin(), nums.end());
    return (i + (i + k - 1)) * k / 2;
}
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    std::vector<int> res;
    std::set<int> s;
    for (int i = 0; i < A.size(); i++) {
        s.insert(A[i]);
        int r = 0;
        for (int j = 0; j <= i; j++) {
            if (s.count(B[j])) {
                r++;
            }
        }
        res.push_back(r);
    }
    return res;
}

#include <queue>

int getCtr(vector<vector<int>>& g, int r, int c) {
    if (g[r][c] <= 0) return 0;
    std::queue<pair<int, int>> q;
    int fish = 0;
    q.push({r, c});
    int x[]{1, -1, 0, 0};
    int y[]{0, 0, 1, -1};

    while (!q.empty()) {
        auto top = q.front();
        fish += g[top.first][top.second];
        g[top.first][top.second] = 0;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = top.first + x[i];
            int nc = top.second + y[i];
            if (nr >= 0 && nr < g.size() && nc >= 0 && nc < g[0].size() && g[nr][nc] > 0) {
                q.push({nr, nc});
            }
        }
    }
    return fish;
}

int findMaxFish(vector<vector<int>>& grid) {
    int res = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int m = getCtr(grid, i, j);
            if (res < m) {
                res = m;
            }
        }
    }
    return res;
}

struct ListNode {
    int v;
    ListNode* p{nullptr};
    ListNode* n{nullptr};
    ListNode(int val) : v(val) {}
};

void printList(ListNode* node) {
    auto* p = node;
    while (p) {
        printf("%d->", p->v);
        p = p->n;
    }
    printf("\n");
}
long long countOperationsToEmptyArray(vector<int>& nums) {
    long long int res = 0;
    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;
    std::set<int> m(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        auto* node = new ListNode(nums[i]);
        node->p = tail;
        tail->n = node;
        tail = node;
    }
    tail->n = head;
    head->p = tail;
    auto p = head;
    while (!m.empty()) {
        auto f = m.begin();
        while (p->v != *f) {
            res++;
            p = p->n;
        }

        p->n->p = p->p;
        p->p->n = p->n;
        p = p->n;
        res++;
        m.erase(f);
    }

    return res;
}

int main() {
    std::vector<int> v{1, 2, 4, 3};
    dbg(countOperationsToEmptyArray(v));
    return 0;
}