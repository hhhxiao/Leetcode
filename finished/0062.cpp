#include "dbg.h"

int uniquePaths(int m, int n) {
    int total = m + n - 2;
    n -= 1;
    if (n > total >> 1) n = total - n;
    int sum = 1;
    for (int i = 0; i < n; i++) {
        sum *= total;
        total--;
    }
    return sum;
}

int main(int argc, char const *argv[]) { return 0; }
