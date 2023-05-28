#include <queue>
#include <vector>

#include "dbg.h"

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second < p2.second; }
};
vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    std::map<int, int> m;
    for (auto i : barcodes) m[i]++;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, cmp> q;

    for (auto &kv : m) {
        q.push(kv);
    }

    std::vector<int> res;

    auto last = std::pair<int, int>{-1, 0};
    while (!q.empty()) {
        auto c = q.top();
        q.pop();
        res.push_back(c.first);
        if (last.second > 0) q.push(last);
        c.second--;
        last = c;
    }

    return res;
}
int main() {
    vector<int> i{1, 1, 1, 1, 1, 3, 2, 2, 2, 2, 2, 3, 4, 5, 1, 4, 5, 6, 7, 3};
    dbg(i);

    auto x = rearrangeBarcodes(i);
    dbg(x);
    return 0;
}
