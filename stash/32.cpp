#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <vector>

#include "a.h"

using namespace std;

// 暴力做法
int logest(const std::string& s, int i) {
    if (i >= s.size()) return 0;
    if (s[i] == ')') return 0;

    int n = 0;
    int cur = 0;
    int res = 0;
    while (i < s.size()) {
        if (s[i] == '(') {
            n++;
        } else {
            // )
            if (n == 0) {
                break;
            } else {
                cur += 2;
                n--;
                if (n == 0) {
                    // dbg(cur);
                    res += cur;
                    cur = 0;
                }
            }
        }
        i++;
    }

    return res;
}

int longestValidParentheses(string s) {
    int r = 0;
    int i = 0;
    while (i < s.size()) {
        auto n = logest(s, i);
        r = std::max(r, n);
        if (n == 0) {
            i++;
        } else {
            i += n;
        }
    }
    return r;
}
int main() {
    dbg(longestValidParentheses("()()()((())))()"));
    // dbg(logest("(((())))()()))(((()", 0));
    //()()

    return 0;
}