#include <stdint.h>

#include <vector>

#include "a.h"

using namespace std;
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        uint32_t bit = 0;
        for (auto& n : nums) {
            bit += (static_cast<uint32_t>(n) >> i) & 1u;
        }
        res |= ((bit % 3) << i);
    }

    return res;
}
int main() {
    vector<int> v{3, 3, 3, 4};
    dbg(singleNumber(v));
    return 0;
}
