#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int repeatedNTimes(vector<int>& nums) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end()) return nums[i];
        map[nums[i]]++;
    }
    return -1;
}
