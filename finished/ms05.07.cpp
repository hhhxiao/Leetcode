#include <vector>

#include "dbg.h"

int exchangeBits(int num) {
    int res = 0;
    int idx = 0;
    while (num > 0) {
        auto bits = num % 4;
        if (bits == 1) {
            bits = 2;
        } else if (bits == 2) {
            bits = 1;
        }

        res += bits << (idx << 1);
        idx++;
        num >>= 2;
    }

    return res;
}
int main() {
    for (int i = 0; i < 100; i++) {
        dbg(exchangeBits(i));
    }

    return 0;
}
