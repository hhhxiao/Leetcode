#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int partitionDisjoint(vector<int>& nums) {
    auto sorted = nums;
    std::sort(sorted.begin(), sorted.end());
    std::unordered_map<int, int> map;
    for (int i = 0; i < sorted.size(); i++) {
        map[sorted[i]] = i;
    }

    std::set<int> s;
    int i = 0;
    for (; i < nums.size(); i++) {
        auto iter = map.find(nums[i]);
        s.insert(iter->second);
        if (s.size() == (*s.rbegin()) + 1) {
            break;
        }
    }
    return i;
}

int main() {
    std::vector<int> v = {2, 3, 5, 1, 4, 8, 7, 9};
    partitionDisjoint(v);
    return 0;
}
