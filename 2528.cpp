#include <algorithm>
#include <vector>

#include "dbg.h"

using namespace std;
long long maxPower(vector<int>& stations, int r, int k) {
    std::vector<int> p(stations.size(), 0);
    for (int i = 0; i < stations.size(); i++) {
        int b = std::max(0, i - r);
        int e = std::min(i + r, (int)stations.size() - 1);
        printf("b = %d, e = %d\n", b, e);
        for (int j = b; j <= e; j++) {
            p[j] += stations[i];
        }
    }
    auto min = *std::min_element(stations.begin(), stations.end());
    if (r * 2 + 1 >= stations.size()) return min + k;

    // 没有全覆盖的情况
    for (int i = 0; i < k; i++) {
        // select best position
        // 贪心策略，每次选择最小值，在上述前提下最好能包含第二小的，不能就第三小，以此类推
    }

    return 0;
}

int main() {
    std::vector<int> v{1, 4, 4, 5, 0};
    maxPower(v, 1, 2);

    return 0;
}