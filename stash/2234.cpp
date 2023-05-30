
#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
    std::sort(flowers.begin(), flowers.end());
    vector<int64_t> ufp;
    vector<int64_t> fp(flowers.size(), 0);
    int sum = 0;
    for (int i = 0; i < flowers.size(); i++) {
        sum += flowers[i];
        ufp.push_back((int64_t)((flowers[i]) * (i + 1)) - sum);
    }

    sum = 0;

    int i = 0;
    int left = 0;

    for (i = flowers.size() - 1; i >= 1; i--) {
        int64_t cur = std::max(0, target - flowers[i]);
        fp[i] = cur + sum;
        if (cur + sum > newFlowers) {
            left = newFlowers - sum;
        }
        sum += cur;
    }
    i++;
    int j = 0;
    while (j < flowers.size() && ufp[j] <= left) {
        j++;
    }
    left -= ufp[j - 1];
    j--;

    // dbg(j);

    dbg(ufp);
    dbg(i);
    dbg(fp);
    dbg(left);

    int64_t ma = (int64_t)(flowers.size() - i) * (int64_t)full + (int64_t)(flowers[j] + (left / (j + 1))) * partial;
    printf("i = %d, j = %d left = %d --> v = %ld\n", i, j, left, ma);
    while (i < flowers.size()) {
        left += target - flowers[i];  // 重新剩了一些
        i++;
        // 尝试步进
        int start = ufp[j];
        while (j < flowers.size() && ufp[j] <= left + start) {
            j++;
        }
        left -= ufp[j - 1];
        j--;
        int64_t v = (int64_t)(flowers.size() - i) * full + (int64_t)(flowers[j] + left / (j + 1)) * partial;
        ma = max(ma, v);
        printf("i = %d, j = %d left = %d --> v= %ld\n", i, j, left, v);
    }

    return ma;
}

int main() {
    vector<int> f{1, 1};
    dbg(maximumBeauty(f, 2, 2, 1, 2));
    return 0;
}