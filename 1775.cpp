#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <vector>

#include "a.h"

#define COLOR

using namespace std;
int minOperations(vector<int>& nums1, vector<int>& nums2) {
    auto sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
    auto sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);

    if (sum1 == sum2) return 0;

    if (sum1 > sum2) {
        std::swap(nums1, nums2);
        std::swap(sum1, sum2);
    }

    dbg(nums1);
    dbg(sum1);
    dbg(nums2);
    dbg(sum2);

    array<int, 6> ctr{0};
    // 更小的数组要自增到6，1 能增5 2能增加4

    for (auto i : nums1) {
        ctr[6 - i]++;
    }

    // 更大的数组要降低到1，6可降低到1，5->1
    for (auto i : nums1) {
        ctr[i - 1]++;
    }

    dbg(ctr);
    auto diff = sum2 - sum1;
    dbg(diff);
    int i = 5;
    int res = 0;
    while (i > 0 && diff > 0) {
        // printf("diff = %d , i = %d\n", diff, i);
        if (i * ctr[i] >= diff) {
            res += diff / i;
            if (diff % i != 0) {
                res++;
            }
            diff = 0;
            break;
        } else {
            res += ctr[i];
            diff -= i * ctr[i];
            i--;
        }
        //
    }

    dbg(diff);

    return diff == 0 ? res : -1;
}
int main() {
    vector<int> n1{6, 6};
    vector<int> n2{1};

    dbg(minOperations(n1, n2));
    return 0;
}
