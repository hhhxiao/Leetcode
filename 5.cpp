#include <iostream>
#include <string>

#include "dbg.h"

#define DBG_MACRO_NO_WARNING 1
using namespace std;

string longestPalindrome(string s) {
    const int sz = s.size();
    if (sz <= 1u) return s;
    std::vector<std::vector<int>> status_array(sz, std::vector<int>(sz));
    for (int i = 0; i < sz; i++) {
        status_array[i][i] = 1;
    }
    for (int i = 0; i < sz - 1; i++) {
        bool res = s[i] == s[i + 1];
        status_array[i][i + 1] = (int)res;
    }

    int l1 = 0, l2 = 0, cur_max_len = 1;
    for (int current_len = 3; current_len <= sz; current_len++) {
        for (int j = 0; j <= sz - current_len; j++) {
            int begin_index = j;
            int end_index = j + current_len - 1;
            bool res = status_array[begin_index + 1][end_index - 1] &&
                       s[begin_index] == s[end_index];
            status_array[begin_index][end_index] = (int)res;
            if (cur_max_len < current_len && res) {
                l1 = begin_index;
                l2 = end_index;
            }
        }
    }
    return s.substr(l1, l2 - l1 + 1);
}

int main(int argc, char const *argv[]) {
    dbg(longestPalindrome("123212"));
    return 0;
}
