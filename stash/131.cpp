#include "a.h"
using namespace std;
unordered_map<int, vector<vector<string>>> cache;
bool is(const std::string& s, int b, int e) {
    auto len = e - b + 1;
    for (int i = 0; i < len / 2; i++) {
        if (s[b + i] != s[e - i]) {
            return false;
        }
    }
    return true;
}
vector<vector<string>> part(const std::string& s, int start) {
    if (start == s.size()) return {};
    if (cache.count(start)) return cache[start];
    std::vector<vector<string>> v;
    for (int i = start; i < s.size(); i++) {
        // check if [star,i]
        if (is(s, start, i)) {
            auto sub = std::string(s.begin() + start, s.begin() + i + 1);
            auto tt = part(s, i + 1);
            if (tt.empty()) {
                v.push_back({sub});
            } else {
                for (auto& t : tt) {
                    t.push_back(sub);
                    v.push_back(t);
                }
            }
        }
    }

    cache[start] = v;
    return v;
}

vector<vector<string>> partition(const std::string& s) {
    auto r = part(s, 0);
    for (auto& i : r) {
        std::reverse(i.begin(), i.end());
    }
    return r;
}

int main() {
    std::string s = "111111111111111";
    auto x = partition(s);
    dbg(x.size());
    // for (auto i : x) {
    //     dbg(i);
    // }

    return 0;
}