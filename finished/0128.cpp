#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    dbg(num_set);
    std::unordered_map<int, int> map;
    std::unordered_map<int, int> map_inv;

    int exist1 = false;
    for (auto n : num_set) {
        // check exist (?,n-1] and [n+1,?)
        // check [n+1,?)
        dbg(n);
        auto iter1 = map.find(n + 1);
        if (iter1 != map.end()) {
            int max = iter1->second;
            auto iter2 = map_inv.find(n - 1);
            if (iter2 != map_inv.end()) {
                //[4,4] 5  [6,6]
                int min = iter2->second;
                map.erase(n + 1);
                map[min] = max;
                map_inv.erase(n - 1);
                map_inv[max] = min;

            } else {
                map.erase(n + 1);
                map[n] = max;
                map_inv[max] = n;
            }
        } else {
            auto iter2 = map_inv.find(n - 1);
            if (iter2 != map_inv.end()) {
                int min = iter2->second;
                // min = 2
                //[-1,2] 3 -->[-1,3]
                map[min] = n;
                map_inv.erase(n - 1);
                map_inv[n] = min;

            } else {
                map[n] = n;
                map_inv[n] = n;
            }
        }

        dbg(map);
        dbg(map_inv);
    }

    auto it = map.begin();
    int res = it->second - it->first;
    for (auto& kv : map) {
        auto d = kv.second - kv.first;
        if (res < d) res = d;
    }
    return res + 1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    dbg(longestConsecutive(v));
    return 0;
}
