#include <stdio.h>
int arr[2001]{};
int numTilings(int n) {
    n *= 2;

    arr[0] = 1;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for (int i = 4; i <= n; i++) {
        arr[i] = i % 2 == 0 ? arr[i - 2] + arr[i - 3] * 2 + arr[i - 4]
                            : arr[i - 3] + arr[i - 2];
        arr[i] %= 1000000007;
    }

    return arr[n];
}
int main() {
    printf("%d", numTilings(12));
    return 0;
}