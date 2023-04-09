#include <cstring>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

bool reverseMatching(const std::string& s, int start,
                     const std::vector<std::string>& pats, int index) {
    if (start >= s.size() || index >= pats.size()) {
        if (start == s.size() &&
            std::all_of(pats.begin() + index, pats.end(),
                        [](const std::string& pa) { return pa.size() == 2; })) {
            return true;
        }

        return false;
    };

    printf("Match from position [%d] with pattern %s\n", start,
           pats[index].c_str());
    auto& p = pats[index];
    if (p.size() == 1) {
        if (p[0] == '.' || p[0] == s[start]) {  //匹配成功
            return reverseMatching(s, start + 1, pats, index + 1);
        } else {
            return false;
        }
    } else {
        int end = start;
        while (end < s.size() && (p[0] == '.' || p[0] == s[end])) ++end;
        printf("Find 0 ~ [%d] ' <%c>\n", end - start, p[0]);
        for (auto p = start; p <= end; p++) {
            // printf("Match from %d\n", p);
            if (reverseMatching(s, p, pats, index + 1)) {
                return true;
            }
        }
        return false;
    }
}

bool isMatch(const string& s, const string& p) {
    int idx = 0;

    std::vector<std::string> res;

    //用于简化搜索空间
    while (idx < p.size()) {
        std::string s(1, p[idx]);
        if (idx + 1 < p.size() && p[idx + 1] == '*') {
            ++idx;
            s.push_back('*');
        }
        ++idx;
        if (!res.empty()) {
            if (s.size() != 2 || res.back() != s) {
                res.push_back(s);
            }
        } else {
            res.push_back(s);
        }
    }

    dbg(res);
    auto r = reverseMatching(s, 0, res, 0);
    dbg(r);
    return r;
}

//"mississippi"
//""
int main() {
    //"a" "ab*"
    isMatch("mississippi", "mis*is*ip*.");
    return 0;
}
