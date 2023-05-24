#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include "dbg.h"

using namespace std;

string makeSmallestPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            if (s[i] > s[s.size() - i - 1]) {
                s[i] = s[s.size() - i - 1];
            } else {
                s[s.size() - i - 1] = s[i];
            }
        }
    }
    return s;
}

bool search(const std::vector<int>& v, int start, int current, const int target) {
    // printf("start = %d, sum = %d\n", start, current);
    if (start >= v.size()) return current == target;

    for (int end = start; end <= v.size() - 1; end++) {
        int sum = 0;

        for (int i = start; i <= end; i++) {
            sum *= 10;
            sum += v[i];
        }

        // printf("[%d - %d]: %d\n", start, end, sum);
        if (sum + current <= target && search(v, end + 1, sum + current, target)) {
            return true;
        }
    }
    return false;
}
int ispunish(int n) {
    int sq = n * n;
    std::vector<int> v;
    while (sq > 0) {
        v.push_back(sq % 10);
        sq /= 10;
    }

    for (int i = 0; i < v.size() / 2; i++) {
        std::swap(v[i], v[v.size() - i - 1]);
    }
    // dbg(v);
    return search(v, 0, 0, n);
}

int punishmentNumber(int n) {
    std::vector<int> v{0,   1,   9,   10,  36,  45,  55,  82,  91,  99,  100, 235, 297, 369, 370,
                       379, 414, 657, 675, 703, 756, 792, 909, 918, 945, 964, 990, 991, 999, 1000};
    auto b = std::upper_bound(v.begin(), v.end(), n);
    int sum = 0;
    for (auto it = v.begin(); it < b; it++) {
        sum += (*it) * (*it);
    }
    return sum;
}
int main() {
    punishmentNumber(37);
    return 0;
}