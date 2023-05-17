#include <iostream>

#include "dbg.h"

using namespace std;
#include <vector>

string addSpaces(string s, vector<int>& spaces) {
    int idx = 0;
    std::string res;
    int si = 0;
    while (idx < s.size()) {
        if (si < spaces.size() && idx == spaces[si]) {
            res.push_back(' ');
            si++;
        }
        res.push_back(s[idx]);
        ++idx;
    }
    return res;
}

int main() {
    auto s = std::string("icodeinpython");
    std::vector<int> idx = {1, 5, 7, 9};
    dbg(addSpaces(s, idx));
    return 0;
}
