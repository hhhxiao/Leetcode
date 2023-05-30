#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<string, vector<string>> n;
    for (auto& s : strs) {
        auto key = s;
        std::sort(key.begin(), key.end());
        n[key].push_back(s);
    }
    vector<vector<string>> res;
    for (auto kv : n) {
        res.push_back(kv.second);
    }
    return res;
}