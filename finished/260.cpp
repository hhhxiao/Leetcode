#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

vector<int> singleNumber2(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        res ^= nums[i];
    }
}
vector<int> singleNumber(vector<int>& nums) {
    std::unordered_map<int, int> ctr;
    std::vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        ctr[nums[i]]++;
    }
    for (auto kv : ctr) {
        if (kv.second == 1) {
            v.push_back(kv.first);
        }
    }

    return v;
}
int main(int argc, char const* argv[]) {
    std::vector<int> in = {1, 1, 2, 2, 3, 3, 8, 4, 4, 5};
    dbg(singleNumber(in));
    return 0;
}
