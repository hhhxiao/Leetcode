#include <bitset>
#include <iostream>
#include <vector>

#include "dbg.h"

int countPrimes(int n) {
    std::vector<int> v(n, 0);
    v[1] = 1;
    int prime = 2;
    while (prime * prime < n) {
        int value = prime * 2;
        while (value < n) {
            v[value] = 1;
            value += prime;
        }
        ++prime;
        while (v[prime] && prime < n) {
            ++prime;
        }
    }
    int res = 0;
    for (int i = 2; i < v.size(); i++) {
        if (!v[i]) {
            res++;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    dbg(countPrimes(32342));
    return 0;
}
