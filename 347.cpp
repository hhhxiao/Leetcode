#include <algorithm>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }
    std::vector<std::pair<int, int>> freq;
    for (auto& kv : map) {
        freq.push_back(kv);
    }
    std::partial_sort(
        freq.begin(), freq.end(), freq.begin() + k,
        [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return p1.second > p2.second;
        });

    dbg(freq);

    std::vector<int> res;
    for (int i = 0; i < k; i++) {
        res.push_back(freq[k].first);
    }

    return res;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 2, 3, 4,
                          1, 2, 3, 4, 5, 7, 8, 9, 10};
    topKFrequent(v, 3);
}
