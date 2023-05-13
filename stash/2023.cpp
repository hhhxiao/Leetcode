#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numOfPairs(vector<string>& nums, string target) {
    if (nums.size() < 2) return 0;
    std::unordered_map<std::string, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    while (!nums.empty()) {
        auto num = nums.begin();
    }
}

int main(int argc, char const* argv[]) { return 0; }
