#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;
int maxAbsoluteSum(vector<int>& nums) {
    vector<int> pf;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        pf.push_back(sum);
    }
    dbg(pf);
    int ma = 0;
    int mi = 0;
    for (int i = 0; i < pf.size(); i++) {
        ma = std::max(pf[i], ma);
        mi = std::max(pf[i], mi);
    }

    return ::abs(ma - mi);
}
int main() {
    vector<int> v{2, -5, 1, -4, 3, -2};
    dbg(maxAbsoluteSum(v));
    return 0;
}