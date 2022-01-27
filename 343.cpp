#include <cstdio>
int integerBreak(int n) {
    if (n == 1 || n == 2) return n;
    int res = 1;
    while (n > 4) {
        res *= 3;
        n -= 3;
    }
    return res * n;
}

int main(int argc, char const *argv[]) {
    printf("%d", integerBreak(4));
    return 0;
}
