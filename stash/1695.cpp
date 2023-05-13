#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

int maximumUniqueSubarray(vector<int>& nums) {
    if (nums.empty()) return 0;
    std::unordered_map<int, int> m;
    int b = 0, e = 0;
    int sum = nums[0];
    m[nums[0]] = 0;  // insert into map
    int res = sum;
    // sliding window
    while (e < nums.size()) {
        dbg(m);
        dbg(sum);
        if (res < sum) res = sum;
        ++e;
        int n = nums[e];
        auto it = m.find(n);
        if (it != m.end()) {
            auto pos = it->second;
            while (b <= pos) {
                m.erase(nums[b]);
                sum -= nums[b];
                ++b;
            }
        }
        // insert new one
        m[n] = e;
        sum += n;
    }

    dbg(sum);
    // 1 2 3 4 2 1
}
int main() {
    std::vector<int> v{1, 2, 3, 4, 2, 3, 4, 5};
    maximumUniqueSubarray(v);
    return 0;
}
