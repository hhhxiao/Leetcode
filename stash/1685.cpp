#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
    std::vector<int> prefix(nums.size(), 0);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        prefix[i] = sum;
    }
    dbg(prefix);

    std::vector<int> res;
    res.push_back(sum - nums[0] * nums.size());
    for (int i = 1; i < nums.size(); i++) {
        // left 有 i个
        // right有 size - i - 1个
        res.push_back(nums[i] * i - prefix[i - 1] +                          // left
                      (sum - prefix[i]) - (nums[i] * (nums.size() - i - 1))  // right
        );
    }
    return res;
}

int main() {
    std::vector<int> v{1, 1, 2, 3, 4, 5, 6, 6, 8};
    dbg(getSumAbsoluteDifferences(v));
    return 0;
}