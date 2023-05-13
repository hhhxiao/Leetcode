#include <iostream>
#include <numeric>
#include <vector>

#include "dbg.h"

using namespace std;

int getX(const vector<int>& v, int x) {
    dbg(v);
    int index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0) x -= v[i];
        if (x <= 0) {
            index = i;
            break;
        }
    }

    return index;
}

vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    std::vector<int> b(101, 0);

    for (int i = 0; i < k; i++) {
        b[nums[i] + 50]++;
    }

    std::vector<int> res;
    res.push_back(std::min(0, getX(b, x) - 50));

    for (int i = k; i < nums.size(); i++) {
        b[nums[i] + 50]++;
        b[nums[i - k] + 50]--;
        res.push_back(std::min(0, getX(b, x) - 50));
    }
    return res;
}

int find1(const std::vector<int>& v, int index) {
    int r = v[index];
    index++;
    int step = 0;

    while (index < v.size()) {
        r = std::gcd(r, v[index]);
        step++;
        if (r == 1) {
            return step;
        }
        ++index;
    }
    return -1;
}

int minOperations(vector<int>& nums) {
    // 有1的情况
    int numsof1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            numsof1++;
        }
    }
    if (numsof1 > 0) return nums.size() - numsof1;
    int minstep = INT32_MAX;
    for (int start = 0; start < nums.size() - 1; start++) {
        int st = find1(nums, start);
        if (st > 0 && st < minstep) {
            dbg(st);
            minstep = st;
        }
    }

    if (minstep == INT32_MAX) return -1;
    return nums.size() - 1 + minstep;
}

int main() {
    //[6,10,15]
    std::vector<int> v{6, 8, 4, 3};
    dbg(minOperations(v));
    return 0;
}