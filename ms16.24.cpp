#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

vector<vector<int>> pairSums(vector<int>& nums, int target) {
    std::unordered_map<int, int> table;
    for (int i = 0; i < nums.size(); i++) {
        table[nums[i]]++;
    }

    std::vector<std::vector<int>> res;
    if (target % 2 == 0) {
        auto iter = table.find(target / 2);
        if (iter != table.end()) {
            int cnt = iter->second / 2;
            res = std::vector<std::vector<int>>(
                cnt, std::vector<int>(2, target / 2));
            table.erase(iter);
        }
    }
    while (!table.empty()) {
        auto f = table.begin();
        int r = f->first;
        auto iter = table.find(target - f->first);
        if (iter != table.end()) {
            res.insert(res.end(), min(f->second, iter->second),
                       {f->first, iter->first});
            table.erase(iter);
        }
        table.erase(r);
    }
    dbg(res);
    return res;
}

int main() {
    std::vector<int> v = {5, 5, 6, 6, 6, 7, 4, 7, 7, 4, 7};
    dbg(pairSums(v, 11));
}
