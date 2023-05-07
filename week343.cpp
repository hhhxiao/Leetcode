#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

int getscore(const std::vector<int>& v) {
    int c = 0;
    for (int i = 0; i < v.size(); i++) {
        c += v[i];
        if ((i - 2 >= 0 && v[i - 2] == 10) || (i - 1 > 0 && v[i - 1] == 10)) {
            c += v[i];
        }
    }
    return c;
}

int isWinner(vector<int>& player1, vector<int>& player2) {
    int x1 = getscore(player1);
    int x2 = getscore(player2);
    dbg(x1, x2);
    if (x1 == x2) return 0;
    return x1 > x2 ? 1 : 2;
}
#include <unordered_map>
int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    std::unordered_map<int, pair<int, int>> g;
    int r = mat.size();
    int c = mat[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            g[mat[i][j]] = {i, j};
        }
    }

    std::vector<int> rows(r, 0);  // 每行被填充了几个
    std::vector<int> cols(c, 0);  // 每列被填充了几个
    for (int i = 0; i < arr.size(); i++) {
        auto n = arr[i];
        auto pos = g[n];
        rows[pos.first]++;
        cols[pos.second]++;
        if (rows[pos.first] >= c || cols[pos.second] >= r) {
            return i;
        }
    }

    return -1;
}

int main() { return 0; }
