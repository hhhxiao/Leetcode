#include <algorithm>
#include <vector>

#include "a.h"

using namespace std;

void search(const vector<int>& can, int index, vector<int>& path, int curSum, int target,
            vector<vector<int>>& res) {  //
    if (index >= can.size()) return;

    int x = can[index];

    int n = 0;

    while (curSum <= target) {
        search(can, index + 1, path, curSum, target, res);
        curSum += x;
        path.push_back(x);
        n++;

        if (curSum == target) {
            res.push_back(path);
        }
    }

    for (int i = 0; i < n; i++) path.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::vector<int> path;
    vector<vector<int>> res;
    search(candidates, 0, path, 0, target, res);
    return res;
}

int main() {
    std::vector<int> v{1, 2, 3, 4};
    dbg(combinationSum(v, 20));
    return 0;
}