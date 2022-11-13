#include <iostream>

int subtractProductAndSum(int n) {
    int m = 1;
    int sum = 0;
    while (n > 0) {
        int c = n % 10;
        m *= c;
        sum += c;
    }
    return n - sum;
}