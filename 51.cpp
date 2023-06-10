#include <stdio.h>

#include <string>
#include <vector>

#include "a.h"

using namespace std;

void solve(vector<string>& table, int cur_line, vector<int>& col_cache, vector<int> neg_cache, vector<int> pos_cache,
           vector<vector<string>>& res) {
    if (cur_line >= table.size()) {
        res.push_back(table);
        return;
    }

    for (int i = 0; i < table.size(); i++) {
        if (!col_cache[i] && !pos_cache[i + cur_line] && !neg_cache[i - cur_line + table.size()]) {
            table[cur_line][i] = 'Q';
            col_cache[i] = 1;
            pos_cache[i + cur_line] = 1;
            neg_cache[i - cur_line + table.size()] = 1;
            solve(table, cur_line + 1, col_cache, neg_cache, pos_cache, res);
            table[cur_line][i] = '.';
            col_cache[i] = 0;
            pos_cache[i + cur_line] = 0;
            neg_cache[i - cur_line + table.size()] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> table(n, string(n, '.'));
    vector<int> col_cache(n, 0);
    vector<int> pos_cahce(n * 2 + 1, 0);
    vector<int> neg_cache(n * 2 + 1, 0);
    solve(table, 0, col_cache, pos_cahce, neg_cache, res);
    return res;
}
int main() {
    auto r = solveNQueens(4);
    dbg(r);
}
