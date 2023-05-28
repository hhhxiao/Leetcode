#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1) {
        return to_string(nums[0]);
    } else if (nums.size() == 2) {
        return to_string(nums[0]) + "/" + to_string(nums[1]);
    }
    std::string res = to_string(nums[0]) + "/(";
    for (int i = 1; i < nums.size() - 1; i++) {
        res += to_string(nums[i]) + "/";
    }
    res += to_string(nums.back()) + ")";
    return res;
}

int main() {
    vector<int> v{1, 2, 4};
    dbg(optimalDivision(v));
    return 0;
}