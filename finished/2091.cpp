#include <iostream>
#include <vector>
using namespace std;

int minimumDeletions(vector<int>& nums) {
    if (nums.size() <= 3) return static_cast<int>(nums.size());
    int min_val = INT32_MAX;
    int max_val = INT32_MIN;
    int min_idx = -1, max_idx = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (min_val > nums[i]) {
            min_val = nums[i];
            min_idx = i;
        }
        if (max_val < nums[i]) {
            max_val = nums[i];
            max_idx = i;
        }
    }
    int i_less = min(min_idx, max_idx);
    int i_great = max(min_idx, max_idx);
    int r1 = min(i_great + 1, (int)nums.size() - i_less);
    int r3 = i_less + 1 + nums.size() - i_great;
    return min(r1, r3);
}

int main(int argc, char const* argv[]) { return 0; }
