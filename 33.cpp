#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("max is %d", a > b ? a : b);
    return 0;
}
