#include <cstdio>
#include <vector>

int findMinFibonacciNumbers(int k) {
    std::vector<int> fibs;
    fibs.push_back(1);
    fibs.push_back(2);
    int n = 1;
    while (fibs[n] < 1000000000) {
        fibs.push_back(fibs[n - 1] + fibs[n]);
        n++;
    }
    int start = fibs.size() - 2;
    int res = 0;
    while (k > 0) {
        int count = k / fibs[start];
        res += count;
        k %= fibs[start];
        start--;
    }
    return res;
};

int main(int argc, char const *argv[]) {
    findMinFibonacciNumbers(1232);
    return 0;
}
