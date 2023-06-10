
#include <stdio.h>

#include <string>
#include <vector>

#include "a.h"

using namespace std;

void solve(int cur_line, vector<int>& col_cache, vector<int> neg_cache, vector<int> pos_cache, int& res) {
    if (cur_line >= col_cache.size()) {
        //
        res++;
        return;
    }

    for (int i = 0; i < col_cache.size(); i++) {
        if (!col_cache[i] && !pos_cache[i + cur_line] && !neg_cache[i - cur_line + col_cache.size()]) {
            col_cache[i] = 1;
            pos_cache[i + cur_line] = 1;
            neg_cache[i - cur_line + col_cache.size()] = 1;
            solve(cur_line + 1, col_cache, neg_cache, pos_cache, res);
            col_cache[i] = 0;
            pos_cache[i + cur_line] = 0;
            neg_cache[i - cur_line + col_cache.size()] = 0;
        }
    }
}

int totalNQueens(int n) {
    vector<int> col_cache(n, 0);
    vector<int> pos_cahce(n * 2 + 1, 0);
    vector<int> neg_cache(n * 2 + 1, 0);
    int res = 0;

    solve(0, col_cache, pos_cahce, neg_cache, res);
    return res;
}
int main() {
    auto r = totalNQueens(8);
    dbg(r);
}
