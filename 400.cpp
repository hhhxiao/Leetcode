#include <cmath>
#include <iostream>

using namespace std;
int findNthDigit(int n) {
    int x = n;
    // 1 9
    // 2 90
    // 3 900
    // 4 90000
    // 5 9000000

    int number = 9, bits = 1;
    while (n - number * bits > 0) {
        n -= number * bits;
        number *= 10;
        bits += 1;
    }
    int nth = n / bits;
    int idx = n % bits;
    if (idx == 0) {
        nth--;
        idx = bits;
    }
    idx = bits + 1 - idx;
    int res = 1;
    bits--;
    while (bits > 0) {
        res *= 10;
        bits -= 1;
    }

    res += nth;
    int r = 0;
    for (int i = 0; i < idx; i++) {
        r = res % 10;
        res /= 10;
    }
    return r;
}

int main(int argc, char const *argv[]) {
    findNthDigit(20000000);
    return 0;
}
