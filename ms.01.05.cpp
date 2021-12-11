#include <iostream>
#include <string>

#include "dbg.h"

using namespace std;

bool oneEditAway(string first, string second) {
    if (first == second) return true;

    int l1 = first.size();
    int l2 = second.size();
    if (abs(l1 - l2) >= 2) return false;
    if (l1 == l2) {
        int ctr = 0;
        for (int i = 0; i < l1; i++) {
            if (first[i] != second[i]) {
                ctr++;
            }
        }
        return ctr <= 1;
    }

    auto short_str = first.size() > second.size() ? second : first;
    auto long_str = first.size() > second.size() ? first : second;
    int index = 0;
    while (index < short_str.size()) {
        if (short_str[index] != long_str[index]) {
            break;
        }
        ++index;
    }
    int lidx = index + 1;
    int sidx = index;
    while (sidx < short_str.size()) {
        if (long_str[lidx] != short_str[sidx]) {
            return false;
        }
        ++sidx;
        ++lidx;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    dbg(oneEditAway("a", ""));
    return 0;
}
