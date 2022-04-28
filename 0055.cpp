#include <queue>
#include <vector>

#include "dbg.h"

using namespace std;
// 2 3  1 1 2 2
bool canJump(vector<int>& nums) {
    int max = 0;
    for (int i = 0; i <= max; i++) {
        const int new_max = i + nums[i];
        if (new_max >= nums.size() - 1) {
            return true;
        }
        if (max < new_max) {
            max = new_max;
        }
    }
    return max >= nums.size();
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {3, 1, 1, 1, 0};
    dbg(canJump(v));
    return 0;
}
