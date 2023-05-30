#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
/**
 * count record that how many number has been used
 *
 */
set<vector<int>> R;
void seacrh(int sum, vector<int>& v, int count, const int K) {
    if (count == K) {
        if (sum == 0) {
            std::vector<int> res;
            for (int i = 1; i < 10; i++) {
                if (v[i] == 1) {
                    res.push_back(i);
                }
            }
            R.insert(res);
        }
        return;
    }
    for (int i = 1; i < 10; i++) {
        if (!v[i]) {
            v[i] = 1;
            seacrh(sum - i, v, count + 1, K);
            v[i] = 0;
        }
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    std::vector<int> v(10, 0);
    seacrh(n, v, 0, k);
    vector<vector<int>> res;
    for (auto& s : R) {
        res.push_back(s);
    }
    return res;
}
int main() {
    combinationSum3(6, 33);
    return 0;
}