#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;
vector<string> getFolderNames(vector<string>& names) {
    std::vector<string> res;

    std::unordered_map<std::string, int> s;
    for (auto& name : names) {
        dbg(s);
        auto iter = s.find(name);
        if (iter == s.end()) {
            s.insert({name, 0});
        } else {
            auto index = iter->second + 1;
            while (true) {
                auto str = name + "(" + std::to_string(index) + ")";
                if (!s.count(str)) {
                    s.insert({str, 0});
                    s[name] = index;
                    break;
                }
                index++;
            }
        }
    }

    for (auto& kv : s) {
        res.push_back(kv.first);
    }
    return res;
}
int main() {
    std::vector<std::string> s = {"kaido", "kaido(1)", "kaido", "kaido(1)"};
    getFolderNames(s);
}
