#include <stdint.h>

#include <algorithm>
#include <random>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;

bool isFascinating(int n) {
    auto st = std::to_string(n) + std::to_string(n * 2) + std::to_string(n * 3);
    int arr[10]{0};
    for (auto i : st) {
        arr[i - '0']++;
    }

    if (arr[0] != 0) return false;

    for (int i = 1; i <= 9; i++) {
        if (arr[i] != 1) return false;
    }

    return true;
}

int longestSemiRepetitiveSubstring(string s) {
    int len = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j < s.size() - i + 1; j++) {
            int cnt = 0;
            for (int k = 1; k < i; k++) {
                if (s[k + j] == s[k + j - 1]) cnt++;
            }

            if (cnt <= 1) {
                len = std::max(len, i);
            }
        }
    }
    return len;
}

int sumDistance(vector<int>& nums, string s, int d) {
    for (int i = 0; i < nums.size(); i++) {
        if (s[i] == 'R') nums[i] += d;
        if (s[i] == 'L') nums[i] -= d;
    }
    std::sort(nums.begin(), nums.end());
    vector<long long> pf;
    long long sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        pf.push_back(sum);
    }

    long long res = 0;
    for (int i = 0; i < nums.size(); i++) {
        auto r = pf.back() - pf[i] - (long long)nums[i] * (nums.size() - i - 1);
        res += r;
        res %= 1000000007;
    }

    return res;
}

// 4

std::unordered_map<int, vector<int>> cache;
std::unordered_map<int, vector<int>> m;
vector<int> p;
int L = 0;
bool check(const vector<int>& s) {
    for (int i = 0; i < L; i++) {
        int sum = 0;
        for (auto n : s) {
            sum += cache[n][i];
        }
        if (sum > s.size() / 2) return false;
    }
    return true;
}

bool valid(const vector<int>& s, vector<int>& res) {
    std::unordered_map<int, int> r;
    for (auto& i : s) r[i]++;

    for (auto& kv : r) {
        auto it = m.find(kv.first);
        if (it != m.end() && it->second.size() >= kv.second) {
            for (int i = 0; i < kv.second; i++) {
                res.push_back(it->second[i]);
            }
        } else {
            return false;
        }
    }
    return true;
}

bool c1(vector<int>& res) {
    auto it = m.find(0);
    if (it != m.end()) {
        res = {it->second[0]};
        return true;
    }
    return false;
}

bool c2(vector<int>& res) {
    const int N = p.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vector<int> s{p[i], p[j]};
            if (check(s) && valid(s, res)) {
                dbg(res);
                return true;
            }
        }
    }
    return false;
}
bool c3(vector<int>& res) {
    const int N = p.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                vector<int> s{p[i], p[j], p[k]};
                if (check(s) && valid(s, res)) {
                    dbg(res);
                    return true;
                }
            }
        }
    }
    return false;
}
bool c4(vector<int>& res) {
    const int N = p.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    vector<int> s{p[i], p[j], p[k], p[l]};
                    if (check(s) && valid(s, res)) {
                        dbg(res);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool c5(vector<int>& res) {
    const int N = p.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    for (int x = 0; x < N; x++) {
                        vector<int> s{p[i], p[j], p[k], p[l], p[x]};
                        if (check(s) && valid(s, res)) {
                            dbg(res);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

// bool c2(vector<int>& ns, std::unordered_map<int, vector<int>>& m, vector<int>& res) {
//     const int N = ns.size();
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; i < N; i++) {
//         }
//     }

//     return false;
// }

vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
    // int arr[32]{0};
    for (int j = 0; j < grid.size(); j++) {
        auto& l = grid[j];
        int r = 0;
        for (int i = 0; i < l.size(); i++) {
            r <<= 1;
            r += l[i];
        }
        m[r].push_back(j);
        cache[r] = l;
    }
    dbg(m);
    L = grid[0].size();

    for (auto& kv : m) p.push_back(kv.first);
    std::vector<int> res;
    if (c1(res)) return res;
    if (c2(res)) return res;
    if (c3(res)) return res;
    if (c4(res)) return res;
    if (c5(res)) return res;
    return {};
}

int main() {  // todo
    vector<vector<int>> v{{0, 1, 1, 0}, {0, 0, 0, 1}, {1, 1, 1, 1}};
    dbg(goodSubsetofBinaryMatrix(v));
    return 0;
}