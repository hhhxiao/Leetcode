#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int n_idx = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[n_idx] = nums[i];
            ++n_idx;
        }
    }
    for (; n_idx < nums.size(); n_idx++) {
        nums[n_idx] = 0;
    }
}
