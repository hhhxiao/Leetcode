#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int maxOperations(vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) map[nums[i]]++;

    int res = 0;
    while (!map.empty()) {
        auto iter = map.begin();
        auto r = map.find(k - iter->first);
        if (r != map.end()) {
            if (r == iter) {
                k += r->second / 2;
            } else {
                k += r->second > iter->second ? iter->second : r->second;
                map.erase(r->first);
            }
        }
        map.erase(iter->first);
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int, int> v;
    return 0;
}
