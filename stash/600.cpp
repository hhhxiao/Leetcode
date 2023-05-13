#include "dbg.h"

int fib(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    int r1 = 1;
    int r2 = 2;
    for (int i = 3; i <= x; i++) {
        int temp = r1 + r2;
        r1 = r2;
        r2 = temp;
    }
    return r2;
}

int findIntegers(int n) {
    int x = 0;
    while (n > 0) {
        n >>= 1;
        x++;
    }

    return fib(x);
}

int main() {
    dbg(fib(4));
    return 0;
}
