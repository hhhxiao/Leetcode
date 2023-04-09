#include <string>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;

bool search(const std::string& s, int index,
            const std::unordered_map<char, std::vector<std::string>>& wm,
            std::vector<int>& flags) {
    if (index >= s.size()) {
        return true;
    }

    if (flags[index] == 0) {
        return false;
    }
    auto ch = s[index];
    auto it = wm.find(ch);
    if (it == wm.end()) return false;
    //遍历(这里的查询比较慢，因为只做了第一个字符的索引，可以用前缀树索引所有字符，但是太慢了，懒得写了)
    for (auto& i : it->second) {
        if (s.length() - index >= i.length() && s.find(i, index) == index) {
            //  printf("match %s in position %d\n", i.c_str(), index);
            if (search(s, index + i.size(), wm, flags)) {
                return true;
            }
        }
    }
    flags[index] = 0;
    return false;
}
bool wordBreak(string s, vector<string>& wordDict) {
    std::unordered_map<char, std::vector<std::string>> wm;
    for (auto& i : wordDict) {
        if (!i.empty()) {
            wm[i[0]].push_back(i);
        }
    }
    //   dbg(wm);
    // for (auto& i : wm) {
    //     std::sort(i.second.begin(), i.second.end(),
    //               [](const string& p1, const string& p2) {
    //                   return p1.length() > p2.length();
    //               });
    // }
    // dbg(wm);
    std::vector<int> flags(s.size(), -1);
    return search(s, 0, wm, flags);
}

int main() {
    auto str = std::string(
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
        "aaaaaaaaaa");

    auto dict = std::vector<std::string>{
        "a",      "aa",      "aaa",      "aaaa",      "aaaaa",
        "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};
    dbg(wordBreak(str, dict));
}