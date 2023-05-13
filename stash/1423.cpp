#include <vector>
using namespace std;
#include "dbg.h"
int maxScore(vector<int>& cardPoints, int k) {
    //长为n - k的最小子数组的和
    if (k == 0) return 0;
    k = cardPoints.size() - k;
    int part_sum = 0;
    for (int i = 0; i < k; i++) part_sum += cardPoints[i];
    if (k == cardPoints.size()) return part_sum;
    int res = part_sum;
    int total = part_sum;
    dbg(part_sum);
    int begin = 0;
    while (k < cardPoints.size()) {
        part_sum -= cardPoints[begin];
        part_sum += cardPoints[k];
        if (res > part_sum) res = part_sum;
        total += cardPoints[k];
        dbg(part_sum);
        begin++;
        k++;
    }
    dbg(res, total, total - res);
    return 0;
}

int main() {
    std::vector<int> v{1, 79, 80, 1, 1, 1, 200, 1};
    maxScore(v, 3);
    return 0;
}