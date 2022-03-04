#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
bool canArrange(const vector<int>& arr, int k) {
    std::vector<int> table(k, 0);
    for (int i = 0; i < arr.size(); i++) {
        int mod = arr[i] % k;
        dbg(mod);
        if (mod < 0) mod += k;
        table[mod]++;
    }

    dbg(table);
    int f = 1;
    int e = k - 1;
    while (f < e) {
        if (table[f] != table[e]) {
            return false;
        }
        ++f;
        --e;
    }
    dbg(table);
    // 0 1 2 3 4 5
    if (k % 2 == 0) {
        return table[k / 2] % 2 == 0;
    }

    return true;
}
int main() {
    canArrange({1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, 5);
    return 0;
}
