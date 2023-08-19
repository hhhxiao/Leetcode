#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

int internal_search(const std::vector<int>& nums, int l, int r, int target) {
    // printf("%d ~ %d\n", l, r);
    if (l > r) return -1;

    if (nums[l] == target) return l;
    if (nums[r] == target) return r;
    if (l + 1 >= r) return -1;  // x x+1 | x x

    int mid = (l + r) / 2;

    int vl = nums[l];
    int vm = nums[mid];
    int vr = nums[r];

    if (vl < vm) {
        if (vl <= target && target <= vm) {
            return internal_search(nums, l, mid, target);
        }
        return internal_search(nums, mid, r, target);
    } else if (vm < vr) {
        if (vm <= target && target <= vr) {
            return internal_search(nums, mid, r, target);
        }
        return internal_search(nums, l, mid, target);
    }

    return -1;
}

int search(vector<int>& nums, int target) {
    return internal_search(nums, 0, nums.size() - 1, target);
}

int main() {
    vector<int> v{5, 6, 7, 8, 9, 10, 11, 1, 2, 3, 4};
    for (int i = 0; i < 10; i++) {
        dbg(i);
        dbg(search(v, i));
    }

    return 0;
}
