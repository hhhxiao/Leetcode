#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> findOriginalArray(vector<int>& changed) {
    map<int, int> m;
    for (auto s : changed) {
        m[s]++;
    }
    std::vector<int> res;
    while (!m.empty()) {
        auto last = m.rbegin();
        if (last->first % 2 != 0) return {};
        if (last->first == 0) {
            if (last->second % 2 != 0) {
                return {};
            } else {
                for (int i = 0; i < last->second / 2; i++) {
                    res.push_back(0);
                }
                m.erase(0);
            }
            continue;
        }

        auto ctr = last->second;
        auto half = last->first / 2;
        auto it = m.find(half);
        if (it == m.end()) return {};
        auto count = it->second;
        if (count < ctr) {
            return {};
        } else if (count == ctr) {
            m.erase(last->first);
            m.erase(half);
            for (int i = 0; i < ctr; i++) {
                res.push_back(half);
            }
        } else {
            m.erase(last->first);
            m[half] -= ctr;
            for (int i = 0; i < ctr; i++) {
                res.push_back(half);
            }
        }
    }

    return res;
}
int main() {
    vector<int> i{1, 1, 2, 2, 2, 3, 6, 4, 4, 8};
    auto _ = findOriginalArray(i);
    dbg(_);
    return 0;
}