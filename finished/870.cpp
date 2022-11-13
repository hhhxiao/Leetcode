#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    auto copy = nums2;
    std::sort(nums1.begin(), nums1.end(), std::greater<int>());
    std::sort(nums2.begin(), nums2.end(), std::greater<int>());

    dbg(nums1);
    dbg(nums2);
    const int sz = nums1.size();
    int max = INT32_MIN;
    int max_index = -1;
    for (int i = 0; i < sz; i++) {
        int total = 0;
        for (int j = 0; j < sz - i; j++) {
            if (nums1[j] > nums2[j + i]) {
                total++;
            }
        }

        if (max < total) {
            max = total;
            max_index = i;
        }
    }

    dbg(max_index);
    std::unordered_map<int, std::vector<int>> map;
    for (int j = 0; j < sz - max_index; j++) {
        map[nums2[j + max_index]].push_back(nums1[j]);
    }
    dbg(map);

    for (int i = 0; i < max_index; i++) {
        map[nums2[i]].push_back(nums1[sz - max_index + i]);
    }

    dbg(map);
    std::vector<int> res;
    for (int i = 0; i < copy.size(); i++) {
        auto iter = map.find(copy[i]);
        res.push_back(iter->second.back());
        iter->second.pop_back();
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v1 = {8, 2, 4, 4, 5, 6, 6, 0, 4, 7};

    std::vector<int> v2 = {0, 8, 7, 4, 4, 2, 8, 5, 2, 0};
    advantageCount(v1, v2);
    return 0;
}
