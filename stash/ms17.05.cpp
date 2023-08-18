#include <cctype>
#include <string>
#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;

vector<string> findLongestSubarray(vector<string>& array) {
    vector<int> r;
    vector<int> pf;
    int sum = 0;
    for (auto& s : array) {
        auto i = std::isdigit(s[0]) ? 1 : -1;
        sum += i;
        r.push_back(i);
        pf.push_back(sum);
    }
    dbg(r);
    dbg(pf);
    unordered_map<int, int> ma;
    ma[0] = -1;

    int begin = -1;
    int end = 0;
    int ml = 0;

    for (int i = 0; i < pf.size(); i++) {
        auto it = ma.find(pf[i]);
        if (it == ma.end()) {
            ma[pf[i]] = i;
        } else {
            if (ml < i - it->second) {
                ml = i - it->second;
                end = i;
                begin = it->second;
            }
        }
    }
    // dbg(ml);
    // dbg(begin);
    // dbg(end);
    return std::vector<string>(array.begin() + begin + 1, array.begin() + end + 1);
}
int main() {
    vector<string> s{"A", "1", "B", "C", "D", "2", "3", "4", "E", "5",
                     "F", "G", "6", "7", "H", "I", "J", "K", "L", "M"};
    dbg(findLongestSubarray(s));
    return 0;
}