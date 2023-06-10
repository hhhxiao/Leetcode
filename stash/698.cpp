#include "a.h"
#include "dbg.h"

using namespace std;
vector<int> bucket;
bool search(vector<int>& nums, int index, int target) {
    if (index == nums.size()) {
        return true;
    }
    for (int i = 0; i < bucket.size(); i++) {
        if (bucket[i] + nums[index] > target) {
            continue;
        }
        if (i > 0 && bucket[i] == bucket[i - 1]) {
            continue;
        }
        bucket[i] += nums[index];
        if (search(nums, index + 1, target)) {
            return true;
        }
        bucket[i] -= nums[index];
    }
    return false;
}
bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (k > nums.size()) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    std::sort(nums.rbegin(), nums.rend());
    bucket.resize(k);
    return search(nums, 0, sum / k);
}

int main() {
    vector<int> v{3, 3, 10, 2, 6, 5, 10, 6, 8, 3, 2, 1, 6, 10, 7, 2};
    dbg(canPartitionKSubsets(v, 6));
    return 0;
}