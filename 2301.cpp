#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    unordered_map<char, unordered_set<char>> d;
    for (auto& v : mappings) {
        d[v[0]].insert(v[1]);
    }

    if (s.size() < sub.size()) return false;
    for (int i = 0; i < s.size() - sub.size(); i++) {
        bool success = true;
        for (int j = 0; j < sub.size(); j++) {
            if (s[i + j] != sub[j]) {
                if (!(d.count(sub[j]) > 0 && d[sub[j]].count(s[i + j]))) {
                    success = false;
                    break;
                }
            }
        }
        if (success) return true;
    }
    return true;
}
