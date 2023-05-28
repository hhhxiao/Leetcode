#include <algorithm>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "dbg.h"
#include "io/io.h"

using namespace std;
string removeTrailingZeros(string num) {
    while (num.size() > 0 && num.back() == '0') num.pop_back();
    return num;
}

int cal(vector<vector<int>>& grid, int i, int j) {
    int row = grid.size();
    int col = grid[0].size();

    std::set<int> s1;
    for (int l = 0; l < i; l++) {
        int c = l - i + j;
        if (c >= 0 && c < col) {
            s1.insert(grid[l][c]);
        }
    }
    std::set<int> s2;
    for (int l = i + 1; l < grid.size(); l++) {
        int c = l - i + j;
        if (c >= 0 && c < col) {
            s2.insert(grid[l][c]);
        }
    }
    return abs((int)s1.size() - (int)s2.size());
}

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    auto res = grid;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[i][j] = cal(grid, i, j);
        }
    }
    return res;
}

int64_t ma(std::vector<int64_t>& l, std::vector<int64_t>& r) {
    std::vector<int64_t> x;
    x.push_back(r[0]);
    x.push_back(l[r.size() - 1]);
    for (int i = 0; i < l.size() - 1; i++) {
        x.push_back(l[i] + r[i + 1]);
    }

    return *std::min_element(x.begin(), x.end());
}

std::vector<std::vector<int64_t>> gett(const std::string& s) {
    std::vector<std::vector<int64_t>> t(2, std::vector<int64_t>(s.size(), 0));
    t[0][0] = s[0] == '0' ? 0 : 1;
    t[1][0] = s[0] == '1' ? 0 : 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '0') {
            t[0][i] = t[0][i - 1];
            t[1][i] = s[i - 1] == '1' ? i + 1 + t[0][i - 1] : t[1][i - 1] + 1;
        } else if (s[i] == '1') {
            t[1][i] = t[1][i - 1];
            t[0][i] = s[i - 1] == '0' ? i + 1 + t[1][i - 1] : t[0][i - 1] + 1;
        }
    }

    return t;
}

long long minimumCost(const std::string& s) {
    auto left = gett(s);
    auto sr = s;
    for (int i = 0; i < sr.size() / 2; i++) {
        auto c = sr[i];
        sr[i] = sr[sr.size() - 1 - i];
        sr[s.size() - 1 - i] = c;
    }
    dbg(sr);
    auto right = gett(sr);
    for (int i = 0; i < right[0].size() / 2; i++) {
        std::swap(right[0][i], right[0][right[0].size() - 1 - i]);
        std::swap(right[1][i], right[1][right[0].size() - 1 - i]);
    }
    dbg(left[0]);
    dbg(right[0]);
    dbg(left[1]);
    dbg(right[1]);
    auto a0 = ma(left[0], right[0]);
    auto a1 = ma(left[1], right[1]);
    return std::min(a0, a1);
}

int maxIncreasingCells(vector<vector<int>>& mat) { return 0; }
int main() {
    std::string s = "1111";
    dbg(minimumCost(s));
    return 0;
}