#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;

int maxEqualFreq(vector<int>& nums) {
    unordered_map<int, int> ctr;
    unordered_map<int, int> freq_ctr;
    int res = INT32_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int c = nums[i];
        auto it = ctr.find(c);
        if (it == ctr.end()) {
            freq_ctr[1]++;
        } else {
            freq_ctr[it->second]--;
            if (freq_ctr[it->second] == 0) freq_ctr.erase(it->second);
            freq_ctr[it->second + 1]++;
        }
        ctr[c]++;
        // dbg(freq_ctr);
        if (i + 1 <= 2) {
            res = std::max(i + 1, res);
            continue;
        }
        if (freq_ctr.size() == 1) {
            if (freq_ctr.begin()->first == 1) {
                res = std::max(i + 1, res);
            }
        } else if (freq_ctr.size() == 2) {
            // a个n 1 个m
            if (freq_ctr.count(1) && freq_ctr[1] == 1) {
                res = std::max(i + 1, res);
                continue;
            }

            // a个m 1个(m+1)
            auto fir = freq_ctr.begin();
            auto sec = std::next(fir);
            if ((fir->first == sec->first + 1 && fir->second == 1) ||
                (sec->first == fir->first + 1 && sec->second == 1)) {
                res = std::max(i + 1, res);
            }
        }
    }
    return res;
}
int main() {
    vector<int> v{1, 1, 1, 3, 3};
    dbg(maxEqualFreq(v));
    return 0;
}
