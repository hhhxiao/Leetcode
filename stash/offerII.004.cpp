#include <iostream>
#include <vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int res;
    for (int i = 0; i < 32; i++) {
        int s = 0;
        for (auto n : nums) {
            s = +((n >> i) & 0x1);
        }
        if (s % 3 != 0) {
            res |= (1 << i);
        }
    }
    return res;
}