
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    std::unordered_map<int, int> s;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        s[nums[i]]++;
        sum += nums[i];
    }

    int res = 0;

    int begin = 0;
    int end = k;

    dbg(s, sum);
    if (res < sum && s.size() == k) res = sum;
    do {
        s[nums[begin]]--;
        s[nums[end]]++;
        if (s[nums[begin]] == 0) s.erase(nums[begin]);
        sum -= nums[begin];
        sum += nums[end];
        if (res < sum && s.size() == k) res = sum;
        // printf("remove %d  insert %d\n", nums[begin], nums[end]);
        dbg(s, sum);
        ++begin;
        ++end;
    } while (end < nums.size());

    return res;
}

int main() {
    std::vector<int> v{1, 5, 4, 2, 9, 9, 9};
    dbg(maximumSubarraySum(v, 3));

    return 0;
}
