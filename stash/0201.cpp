#include <iostream>
int rangeBitwiseAnd(int left, int right) {
    unsigned int n = 1u;
    int res = 0;
    while (n < INT32_MAX) {
        int r = (right / n - left / n);
        printf("n = %d,r = %d\n", n, r);
        res += (r % n) * n;
        n <<= 1;
    }
    return res;
}

int main() { printf("%d", rangeBitwiseAnd(0, 4)); }
