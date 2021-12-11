#include <iostream>
#include <queue>
#include <string>

#include "dbg.h"

using namespace std;
string frequencySort(const string &s) {
    int table[128];
    memset(table, 0, 128 * sizeof(int));
    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
    }
    auto Cp = [](pair<int, int> left, pair<int, int> right) {
        return left.second < right.second;
    };

    std::priority_queue<pair<int, int>, std::vector<pair<int, int>>,
                        decltype(Cp)>
        q(Cp);

    for (int i = 0; i < 128; i++) {
        if (table[i] != 0) q.push({i, table[i]});
    }

    std::string res;
    dbg("Here!");
    while (!q.empty()) {
        auto c = q.top();
        dbg(c);
        res += std::string(c.second, (char)c.first);
        q.pop();
    }
    return res;
}

int main(int argc, char const *argv[]) {
    dbg(frequencySort("abaacec"));
    return 0;
}
