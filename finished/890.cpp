#include <string>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

// aabbcxyx
std::vector<int> calPat(const std::string& s) {
    std::unordered_map<char, std::vector<int>> p;
    std::vector<int> firsts;
    for (int i = 0; i < s.size(); i++) {
        auto iter = p.find(s[i]);
        if (iter == p.end()) {
            firsts.push_back(i);
        }
        p[s[i]].push_back(i);
    }

    std::vector<int> res;
    for (int i = 0; i < firsts.size(); i++) {
        auto it = p.find(s[firsts[i]]);
        if (it != p.end()) {
            for (auto idx : it->second) {
                res.push_back(idx);
            }
            res.push_back(-1);
        }
    }
    return res;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    auto target_pattern = calPat(pattern);
    std::vector<string> res;
    // dbg(target_pattern);
    for (auto& w : words) {
        auto p = calPat(w);
        //   dbg(p);
        if (target_pattern == p) {
            res.push_back(w);
        }
    }
    return res;
}

int main() {
    std::vector<std::string> s = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    const std::string pat = "egg";
    dbg(findAndReplacePattern(s, pat));
    // calPat(pat);
    return 0;
}