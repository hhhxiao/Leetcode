#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

std::unordered_map<int, int> cache;
std::unordered_set<std::string> d;

int findMin(int start, const std::string& s) {
    if (cache.count(start)) {
        return cache[start];
    }
    int remain_min = s.size() - start;
    for (auto& k : d) {
        auto it = s.find(k, start);
        int r = it == std::string::npos ? s.size() - start : (it - start) + findMin(it + k.size(), s);
        remain_min = std::min(remain_min, r);
    }
    cache[start] = remain_min;
    return remain_min;
}
int minExtraChar(const string& s, vector<string>& dictionary) {
    for (auto& v : dictionary) d.insert(v);
    return findMin(0, s);
}
long long maxStrength(vector<int>& v) {
    std::sort(v.begin(), v.end());
    std::vector<int> select;

    int index = 0;
    while (index < v.size()) {
        dbg(index);
        if (v[index] > 0) {
            select.push_back(v[index]);
            index++;
        } else if (v[index] < 0) {
            if (index + 1 < v.size() && v[index + 1] < 0) {
                select.push_back(v[index]);
                select.push_back(v[index + 1]);
                index += 2;
            } else {
                ++index;
            }
        } else if (v[index] == 0) {
            ++index;
        }
    }

    if (select.empty()) select.push_back(v.back());
    int64_t x = 1;
    for (auto i : select) x *= (uint64_t)(i);
    return x;
}

// void init(int n) {
//     fa = std::vector<int>(n, 0);
//     for (int i = 0; i < n; i++) {
//         fa[i] = i;
//     }
//}

std::vector<int> fa;
void init(int n) {
    fa = std::vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}

// 查询
int find(int x) {
    if (x != fa[x])           // x 不是自身的父亲，即 x 不是该集合的代表
        fa[x] = find(fa[x]);  // 查找 x 的祖先直到找到代表，于是顺手路径压缩
    return fa[x];
}

// 合并
void unionSet(int x, int y) {
    // x 与 y 所在家族合并
    x = find(x);
    y = find(y);
    fa[x] = y;  // 把 x 的祖先变成 y 的祖先的儿子
}

bool canTraverseAllPairs(vector<int>& v) {
    std::set<int> se(v.begin(), v.end());
    std::vector<int> nums(se.begin(), se.end());
    for (auto i : nums) {
        if (i == 1) {
            return false;
        }
    }
    std::sort(nums.begin(), nums.end());
    dbg(nums);
    init(nums.size());
    for (int i = nums.size() - 2; i >= 0; i--) {
        for (int j = nums.size() - 1; j > i; j--) {
            if (nums[j] % nums[i] == 0) {
                unionSet(i, j);
                break;
            } else if (std::gcd(nums[i], nums[j]) > 1) {
                unionSet(i, j);
            }
        }
    }

    std::unordered_map<int, std::unordered_set<int>> s;
    for (int i = 0; i < nums.size(); i++) {
        s[nums[(find(i))]].insert(nums[i]);
    }
    dbg(s);
    return s.size() == 1;
}
int main() {
    std::vector<int> x{12, 3, 4, 9};
    dbg(canTraverseAllPairs(x));

    return 0;
}