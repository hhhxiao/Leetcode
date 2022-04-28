#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

//仅最前面的五位有数字
// 0x000 FFFFF
int to_int(uint64_t v) {
    if ((v >> 16) & 0xA) v |= 0XFFF00000;
    return v;
}

uint64_t hash_triple(int v1, int v2, int v3) {
    if (v1 > v2) std::swap(v1, v2);
    if (v1 > v3) std::swap(v1, v3);
    if (v2 > v3) std::swap(v2, v3);
    uint64_t hash = ((static_cast<uint64_t>(v1) << 40) & 0x0FFFFF0000000000) |
                    ((static_cast<uint64_t>(v2) << 20) & 0x000000FFFFF00000) |
                    (static_cast<uint64_t>(v3) & 0x00000000000FFFFF);

    printf("hash:%llx, %d %d %d\n", hash, v1, v2, v3);
    return hash;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }
    std::unordered_set<uint64_t> set;
    std::vector<std::vector<int>> res;
    for (auto& i : map) {
        i.second--;
        for (auto& j : map) {
            if (j.second > 0) {
                j.second--;
                auto iter = map.find(-j.first - i.first);
                if (iter != map.end() && iter->second > 0) {
                    auto hash = hash_triple(i.first, j.first, iter->first);
                    set.insert(hash);
                }
                j.second++;
            }
        }
        i.second++;
    }
    for (auto& hash : set) {
        auto v1 = to_int(hash >> 40);
        auto v2 = to_int((hash >> 20) & 0xFFFFF);
        auto v3 = to_int(hash & 0xFFFFF);
        res.push_back({v1, v2, v3});
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {0, -97960, 97960};
    dbg(threeSum(v));
    return 0;
}
