#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int kConcatenationMaxSum(vector<int>& arr, int k) {
    if (arr.empty() || k == 0) return 0;
    int sub_max = arr[0];
    int sub_min = -arr[0];
    int sum = arr[0];
    int mi = INT_MIN;
    int ma = INT_MIN;

    int head_max = INT_MIN;
    int head_min = INT_MAX;

    for (int i = 1; i < arr.size(); i++) {
        sum += arr[i];
        sub_max = max(sub_max + arr[i], arr[i]);
        sub_min = max(sub_min - arr[i], -arr[i]);

        if (head_max < sum) head_max = sum;
        if (head_min > sum) head_min = sum;

        if (ma < sub_max) ma = sub_max;
        if (mi < sub_min) mi = sub_min;
    }
    mi = -mi;

    printf("sum = %d\n max = %d min = %d left max = %d, right max = %d", sum,
           ma, mi, head_max, sum - head_min);
    if (sum <= 0 || k == 1) return ma;

    int64_t x1 = (int64_t)k * sum;
    int64_t x2 = (int64_t)(k - 1) * sum + max(sum - head_min, head_max);
    int64_t x3 = (int64_t)(k - 2) + head_max + (sum - head_min);
    return max(max(x1, x2), x3) % 1000000007;
}

int main() {
    std::vector<int> v{
        5, 4, -8, 2, -1, 7,
    };
    kConcatenationMaxSum(v, 10);
    return 0;
}