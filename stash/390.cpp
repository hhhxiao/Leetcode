#include <iostream>
#include <vector>

#include "dbg.h"

int lastRemaining(int n) {
    int start = 1;
    int size = n;
    int space = 1;

    while (size >= 4) {
        int x = size % 4;
        if (x == 0 || x == 1) {
            start += space;
        } else {
            start += space * 3;
        }

        size /= 4;
        space *= 4;
    }

    if (size == 1) return start;
    if (size == 2 || size == 3) return start + space;
    return -1;
}

int main() {
    dbg(lastRemaining(100000));
    return 0;
}