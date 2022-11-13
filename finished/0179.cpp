#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

string largestNumber(vector<int>& nums) {
    std::vector<std::string> strs;
    for (int i = 0; i < nums.size(); i++) {
        strs.push_back(to_string(nums[i]));
    }

    std::sort(strs.begin(), strs.end(), [](const string& s1, const string& s2) {
        return s1 + s2 > s2 + s1;
    });

    int index = 0;
    std::string res;
    while (strs[index] == "0") ++index;
    for (int i = index; i < strs.size(); i++) {
        res += strs[i];
    }
    return res.empty() ? "0" : res;
}

int main(int argc, char const* argv[]) {
    vector<int> v = {3, 30, 34, 5, 9};
    dbg(largestNumber(v));
    return 0;
}
