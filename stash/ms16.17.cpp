#include <vector>
using namespace std;
#include <set>

#include "dbg.h"

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    std::vector<int> prefix;
    prefix.push_back(sum);
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefix.push_back(sum);
    }

    dbg(prefix);
    std::set<int> s;
    s.insert(prefix[0]);
    int max_sum = INT32_MIN;
    for (int i = 1; i < prefix.size(); i++) {
        int sum = prefix[i] - *s.begin();
        printf("pf[%d] = %d, begin = %d\n", prefix[i], i, *s.begin());
        s.insert(prefix[i]);
        if (max_sum < sum) max_sum = sum;
    }
    return max_sum;
}

int main() {
    std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << maxSubArray(v);
}