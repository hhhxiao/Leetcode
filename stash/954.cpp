#include <iostream>
#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
bool check(map<int, int>& m) {
    //  TODO
    while (!m.empty()) {
        auto num = m.rbegin()->first;
        auto ctr = m.rbegin()->second;
        if (num % 2 != 0) return false;
        auto half = num >> 1;
        auto it = m.find(half);
        if (it == m.end()) return false;
        if (it->second < ctr) return false;
        if (it->second == ctr) {
            // remove
            m.erase(half);
        } else {
            m[half] = it->second - ctr;
        }
        m.erase(num);
    }

    return true;
}
bool canReorderDoubled(vector<int>& arr) {
    map<int, int> neg, pos;
    int zeros;
    for (auto v : arr) {
        if (v > 0) pos[v]++;
        if (v < 0) neg[-v]++;
        if (v == 0) zeros++;
    }
    if (zeros % 2 != 0) return false;
    return check(neg) && check(pos);
}
int main() {
    vector<int> v{1, 2, 2, 4, 8};
    map<int, int> m;
    for (auto x : v) m[x]++;
    printf("%d", check(m));
    return 0;
}