#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    std::unordered_map<int, std::vector<int>> ump;
    for (int i = 0; i < groupSizes.size(); i++) {
        ump[groupSizes[i]].push_back(i);
    }
    std::vector<std::vector<int>> res;
    for (auto& kv : ump) {
        int groups = kv.second.size() / kv.first;
        for (int i = 0; i < groups; i++) {
            res.emplace_back(kv.second.begin() + i * kv.first,
                             kv.second.begin() + (i + 1) * kv.first);
        }
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {2, 1, 3, 3, 3, 2};
    dbg(groupThePeople(v));
    return 0;
}
