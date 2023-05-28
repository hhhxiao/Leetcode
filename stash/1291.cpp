#include <vector>

#include "dbg.h"

using namespace std;
void gs(int bit, int low, int high, std::vector<int>& v) {
    int add = 0;
    int init = 0;
    for (int i = 0; i < bit; i++) {
        add *= 10;
        add += 1;
        init *= 10;
        init += (i + 1);
    }

    std::vector<int> res;
    for (int i = 0; i <= (9 - bit); i++) {
        auto r = i * add + init;
        if (r >= low && r <= high) {
            v.push_back(r);
        }
    }
}

vector<int> sequentialDigits(int low, int high) {
    std::vector<int> v;
    for (int i = 1; i < 10; i++) {
        gs(i, low, high, v);
    }
    return v;
}

int main() {
    dbg(sequentialDigits(20, 781));
    return 0;
}