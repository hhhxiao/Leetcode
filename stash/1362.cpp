#include <stdint.h>

#include <array>

#include "a.h"

using namespace std;

void check(int x, int& a, int& b) {
    a = 1;
    b = x;
    int i = 1;
    int diff = b - a;
    while (i * i <= x) {
        if (x % i != 0) {
            i++;
            continue;
        }
        int n = x / i;
        if (n - i < diff) {
            diff = n - i;
            a = i;
            b = n;
        }
        i++;
    }
}

vector<int> closestDivisors(int num) {
    int a1, b1;
    check(num + 1, a1, b1);
    int a2, b2;
    check(num + 2, a2, b2);
    if (abs(a1 - b1) < abs(a2 - b2)) return {a1, b1};
    return {a2, b2};
}

int main() {
    dbg(closestDivisors(999));
    return 0;
}
