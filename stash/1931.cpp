#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

std::vector<int> v;
std::unordered_map<int, std::unordered_set<int>> ma;

void search_one_line(int cur, int value, int max) {
    if (cur > max) {
        printf("%d\n", value);
        v.push_back(value);
        return;
    }
    int last = value % 10;
    for (int i = 1; i <= 3; i++) {
        if (i != last) {
            search_one_line(cur + 1, value * 10 + i, max);
        }
    }
}
bool adj(int i, int j, int n) {
    std::vector<int> s1;
    std::vector<int> s2;
    while (i > 0) {
        s1.push_back(i % 10);
        i /= 10;
    }
    while (j > 0) {
        s2.push_back(j % 10);
        j /= 10;
    }
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            return false;
        }
    }
    return true;
}
int colorTheGrid(int m, int n) {
    search_one_line(1, 0, m);
    for (auto i : v) {
        int ctr = 0;
        for (auto j : v) {
            if (adj(i, j, m)) {
                ma[i].insert(j);
                ma[j].insert(i);
            }
        }
    }
    std::unordered_map<int, int> rev;
    for (int i = 0; i < v.size(); i++) {
        rev[v[i]] = i;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(v.size(), 1));
    for (int col = 1; col < n; col++) {
        for (int i = 0; i < v.size(); i++) {
            auto &it = ma[v[i]];
            int res = 0;
            for (auto &s : it) {
                res += dp[col - 1][rev[s]];
                res %= 1000000007;
            }
            dp[col][i] = res;
        }
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += dp[n - 1][i];
        ans %= 1000000007;
    }
    return ans;
}
int main() {
    colorTheGrid(5, 120);
    return 0;
}
