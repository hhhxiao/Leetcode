#include <algorithm>
#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
int sumSubseqWidths(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    constexpr auto M = 1000000007;

    std::vector<int> mod2(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        mod2[i] = (mod2[i - 1] * 2) % M;
    }

    size_t min_v = 0;
    size_t max_v = 0;
    for (int i = 0; i < nums.size(); i++) {
        max_v += ((nums[i] % M) * mod2[i]) % M;
        min_v += ((nums[i] % M) * mod2[nums.size() - 1 - i]) % M;
        max_v %= M;
        min_v %= M;
    }

    return (max_v + M - min_v) % M;
}
int main() {
    std::vector<int> v{2};
    dbg(sumSubseqWidths(v));
}
