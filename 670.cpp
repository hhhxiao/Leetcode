#include <iostream>
#include <vector>

#include "dbg.h"

//从前往后找到第一个非最大的数字
int maximumSwap(int num) {
    int t = num;
    std::vector<int> v;
    while (num > 0) {
        v.push_back(num % 10);
        num /= 10;
    }
    auto ordered = v;
    std::sort(ordered.begin(), ordered.end());
    int sz = -1;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != ordered[i]) {
            sz = i;
            break;
        }
    }
    dbg(v, ordered);
    if (sz == -1) {
        return t;
    }
    dbg(sz);
    int temp = v[sz];
    int target = ordered[sz];
    dbg(temp, target);
    for (int i = 0; i < sz; i++) {
        if (v[i] == target) {
            v[i] = temp;
            v[sz] = target;
            break;
        }
    }
    dbg(v);
    int sum = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        sum *= 10;
        sum += v[i];
    }
    return sum;
}
int main(int argc, char const *argv[]) {
    dbg(maximumSwap(1993));
    return 0;
}
