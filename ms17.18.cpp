#include <iostream>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
    // 找到第一个存在的数字为止
    unordered_set<int> num_set;
    for (auto i : small) num_set.insert(i);
    int idx = 0;
    while (idx < big.size() && !num_set.count(big[idx])) {
        ++idx;
    }
    if (idx >= big.size()) return {};
}
int main() {}