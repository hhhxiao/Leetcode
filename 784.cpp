#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

void search(const std::vector<int>& v, const std::string& ori, int index,
            std::string& s, std::vector<string>& res) {
    if (index >= v.size()) {
        res.push_back(s);
        return;
    }
    int next = v[index];

    int begin = index == 0 ? 0 : v[index - 1] + 1;
    for (int i = begin; i < next; i++) {
        s.push_back(ori[i]);
    }

    s.push_back(std::toupper(ori[next]));
    auto s_upper = s;
    search(v, ori, index + 1, s_upper, res);
    s.pop_back();
    s.push_back(std::tolower(ori[next]));
    auto s_lower = s;
    search(v, ori, index + 1, s_lower, res);
}

vector<string> letterCasePermutation(const string& s) {
    std::vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (!('0' <= s[i] && s[i] <= '9')) {
            v.push_back(i);
        }
    }
    int index = 0;
    std::string value;
    std::vector<string> res;
    search(v, s, 0, value, res);
    return res;
}

int main() {
    dbg(letterCasePermutation("1a2bxyz"));
    return 0;
}