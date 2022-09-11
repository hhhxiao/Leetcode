#include <cmath>

#include "dbg.h"

int get_sum(int x) {
    int x2 = x << 1;
    return x2 * (x + 1) * (x2 + 1);
}

long long minimumPerimeter(long long neededApples) {
    // 4x^3 <2x(x+1)(2x+1) < 4(x+1)^3
    int x = static_cast<int>(pow(neededApples >> 2, 1.0 / 3));
    if (get_sum(x) >= neededApples) return x << 3;
    return (x + 1) << 3;
    return 0;
}

int main() {
    for (int i = 0; i < 10; i++) {
        dbg(get_sum(i));
    }
    return 0;
}
