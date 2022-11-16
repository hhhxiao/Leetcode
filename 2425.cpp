#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int xor_arr(const std::vector<int>& v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        res ^= v[i];
    }
    return res;
}

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    auto x1 = nums2.size() % 2 == 0 ? 0 : xor_arr(nums1);
    auto x2 = nums1.size() % 2 == 0 ? 0 : xor_arr(nums2);
    return x1 ^ x2;
}
