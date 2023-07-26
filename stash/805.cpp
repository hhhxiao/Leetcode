
#include <algorithm>
#include <functional>
#include <numeric>
#include <system_error>
#include <unordered_set>
#include <vector>

#include "a.h"

using namespace std;

void traversesum(vector<int>& nums, vector<int>& buf, int s, int e,
                 const std::function<void(const std::vector<int>&)>& f) {
    if (s >= e) {
        f(buf);
        return;
    }

    for (int i = s; i < e; i++) {
        buf.push_back(nums[i]);
        traversesum(nums, buf, i + 1, e, f);
        buf.pop_back();
    }
    f(buf);
}

bool splitArraySameAverage(vector<int>& nums) {
    if (nums.size() <= 1) return false;
    for (int i = 0; i < nums.size(); i++) nums[i] *= nums.size();
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    int avg = sum / nums.size();
    for (int i = 0; i < nums.size(); i++) nums[i] -= avg;
    dbg(nums);

    unordered_map<int, unordered_set<int>> ls;
    bool found = false;
    vector<int> buf;
    traversesum(nums, buf, 0, nums.size() / 2, [&](const vector<int>& v) {
        auto sum = std::accumulate(v.begin(), v.end(), 0);
        ls[sum].insert(v.size());
    });

    dbg(ls);
    buf.clear();
    traversesum(nums, buf, nums.size() / 2, nums.size(), [&](const vector<int>& v) {
        auto sum = std::accumulate(v.begin(), v.end(), 0);
        auto it = ls.find(-sum);
        if (it == ls.end()) return;

        for (auto& s : it->second) {
            if (s + v.size() != nums.size() && s + v.size() != 0) {
                found = true;
                break;
            }
        }
    });

    return found;
}

int main() {
    vector<int> v{1, 2, 1};
    dbg(splitArraySameAverage(v));
    return 0;
}
