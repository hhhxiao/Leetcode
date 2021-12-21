#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
    unordered_map<int, vector<int, int>> map_;

   public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            this->map_[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto iter = this->map_.find(target);
        if (iter == this->map_.end()) return -1;
        return iter->second[rand() % (iter->second.size() - 1)];
    }
};
int main(int argc, char const* argv[]) { return 0; }
