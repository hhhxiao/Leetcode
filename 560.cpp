#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    std::map<int, int> m;
    m[0]++;
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        auto iter = m.find(sum - k);
        if (iter != m.end()) {
            res += iter->second;
            printf("%d + %d = %d\n", iter->first, k, sum);
        }
        m[sum]++;
    }
    dbg(res);
    return res;
}
int main() {
    std::vector<int> v = {1, 0, 1};
    subarraySum(v, 1);
    return 0;
}
