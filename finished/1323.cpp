#include <iostream>

int maximum69Number(int num) {
    if (num / 1000 == 6) return num + 3000;
    if ((num % 1000) / 100 == 6) return num + 300;
    if ((num % 100) / 10 == 6) return num + 30;
    if (num % 10 == 6) return num + 3;
    return num;
}

int main(int argc, char const *argv[]) {
    printf("%d", maximum69Number(6999));
    return 0;
}
