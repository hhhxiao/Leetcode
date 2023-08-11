#include <algorithm>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;
long long maxArrayValue(vector<int>& nums) {
    std::vector<long long> p;
    int i = nums.size() - 1;
    while (i >= 0) {
        if (p.empty()) {
            p.push_back(nums[i]);
        } else {
            if (p.back() >= nums[i]) {
                p.back() += static_cast<long long>(nums[i]);
            } else {
                p.push_back(nums[i]);
            }
        }
        i--;
    }
    dbg(p);
    return *std::max_element(p.begin(), p.end());
}

int main() {
    std::vector<int> v{2, 3, 7, 9, 3};
    dbg(maxArrayValue(v));
}