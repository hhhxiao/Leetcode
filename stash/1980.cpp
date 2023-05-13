#include <bitset>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;
string findDifferentBinaryString(vector<string>& nums) {
    std::unordered_set<int> set;
    for (auto& s : nums) {
        auto n = std::bitset<16>(s).to_ullong();
        set.insert(n);
    }
    dbg(set);
    int max = 1 << nums[0].size();
    int v = 0;
    while (v < max) {
        if (!set.count(v)) {
            return std::bitset<16>(v).to_string().substr(16 - nums[0].size());
        }
        ++v;
    }
    return "";
}

int main() {
    std::vector<std::string> s{"000", "001", "100", "111"};
    dbg(findDifferentBinaryString(s));
    return 0;
}