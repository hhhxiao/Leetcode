#include <vector>
using namespace std;

int arraySign(vector<int>& nums) {
    int lt = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) {
            lt++;
        } else if (nums[i] == 0) {
            return 0;
        }
    }
    return lt % 2 == 0 ? 1 : -1;
}
