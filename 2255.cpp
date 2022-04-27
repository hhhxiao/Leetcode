#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    std::map<int, int> m;
    std::set<int> all_players;
    for (auto& r : matches) {
        all_players.insert(r[0]);
        all_players.insert(r[1]);
        m[r[1]]++;
    }

    std::vector<int> no_fail, fail_1;
    for (auto& kv : m) {
        if (kv.second == 1) {
            fail_1.push_back(kv.first);
        }
    }

    for (auto p : all_players) {
        if (!m.count(p)) {
            no_fail.push_back(p);
        }
    }
    return {no_fail, fail_1};
}
