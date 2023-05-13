#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
//[2 3 1 13 2 23 4 23 41 231]
//经典dp题
int jump(vector<int>& nums) {
    std::vector<int> vect(nums.size(), 0);
    for (int i = nums.size() - 2; i >= 0; i--) {
        int maxStep = nums[i];
        dbg(maxStep);
        int lookup = min(static_cast<int>(nums.size() - 1 - i), maxStep);
        dbg(lookup);

        int min = 100000000;
        for (int j = 1; j <= lookup; j++) {
            if (min > vect[i + j]) {
                min = vect[i + j];
            }
        }
        vect[i] = min + 1;
        dbg(vect);
    }

    return vect[0];
}

int main(int argc, char const* argv[]) {
    std::vector<int> v{2, 3, 0, 1, 4};
    jump(v);
    return 0;
}
