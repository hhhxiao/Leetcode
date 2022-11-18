#include <cstdio>
#include <iostream>
#include <vector>

int minimumNumbers(int num, int k) {
    // 10 * x1 + k
    // 10 * x2 + k
    //...
    // 10 * xn + k

    // nK + 10(x1+x2 + ... + xn) = num
    // x1 + x2 + ... + xn = x =  (num - nK) / 10
    // num - nk === 0  (mod 10)
    if (num == 0) return 0;
    if (num == k) return 1;
    if (num < k * 2) return -1;

    std::vector<std::vector<int>> v{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0},
        {0, 2, 4, 6, 8, 0, 2, 4, 6, 8, 0}, {0, 3, 6, 9, 2, 5, 8, 1, 4, 7, 0},
        {0, 4, 8, 2, 6, 0, 4, 8, 2, 6, 0}, {0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 0},
        {0, 6, 2, 8, 4, 0, 6, 2, 8, 4, 0}, {0, 7, 4, 1, 8, 5, 2, 9, 6, 3, 0},
        {0, 8, 6, 4, 2, 0, 8, 6, 4, 2, 0}, {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};

    int x = num % 10;

    for (int i = 1; i <= 10; i++) {
        if (v[k][i] == x) {
            int x = (num - i * k) / 10;
            printf("check %d:  (num -nK)/10 = %d   ", i, x);
            // i个正数字加起来要等于x
            if (x < 0) {
                printf("invalid\n");
                continue;
            } else {
                printf("success\n");
                return i;
            }
        }
    }
    return -1;
}

int main() {

    std::cout << "res is " << minimumNumbers(10, 3);
    return 0;
}
