#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
long long zeroFilledSubarray(const vector<int>& nums) {
    int start = -1;
    int end = -1;
    std::unordered_map<long long, long long> map;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (start == -1) {  // new array
                start = i;
            }
            end = i;
        } else {
            if (start != -1) {
                map[end - start + 1]++;
                start = end = -1;
            }
        }
    }

    if (start != -1) {
        map[end - start + 1]++;
    }
    //    dbg(map);

    long long res = 0;
    for (auto& kv : map) {
        res += kv.first * (kv.first + 1) * kv.second / 2;
    }
    return res;
}

int main() {
    dbg(zeroFilledSubarray({0, 0, 0, 1, 0, 0}));
    return 0;
}