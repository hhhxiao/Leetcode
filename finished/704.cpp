#include <algorithm>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target) return -1;
    return it - nums.begin();
}