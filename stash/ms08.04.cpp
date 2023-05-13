#include <vector>

#include "dbg.h"

using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
    std::vector<std::vector<int>> vect;
    size_t total_num = 1 << nums.size();

    for (int i = 0; i < total_num; i++) {
        std::vector<int> v;
        int n = i;
        for (int j = 0; j < nums.size(); j++) {
            if (n % 2 != 0) {
                v.push_back(nums[j]);
            }
            n >>= 1;
        }
        dbg(v);
        vect.push_back(v);
    }

    return vect;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4};
    subsets(v);
    return 0;
}