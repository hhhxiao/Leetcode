#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool is_similar(const std::string& s1, const std::string& s2) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (s1[i] == s2[i]) {
            cnt++;
        }
    }
    return cnt == 1;
}

int minMutation(string start, string end, vector<string>& bank) {
    std::vector<int> flags(bank.size(), 0);
    std::queue<std::pair<std::string, int>> q;
    q.push({start, 0});
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top.first == end) {
            return top.second;
        }
        for (int i = 0; i < bank.size(); i++) {
            if (0 == flags[i] && is_similar(top.first, bank[i])) {
                flags[i] = 1;
                q.push({bank[i], top.second + 1});
            }
        }
    }
    return -1;
}