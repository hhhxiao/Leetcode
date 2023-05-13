#include <algorithm>

#include "dbg.h"

/**
 * 在范围[0,n]内 以curr为根节点的字典字树的节点个数
 */

int sub_tree_size(int64_t curr, int64_t n) {
    int64_t steps = 0;
    int64_t front = curr;
    int64_t end = curr;
    while (front <= n) {
        steps += std::min(end, n) - front + 1;
        front = front * 10;
        end = end * 10 + 9;
    }
    return steps;
}

int find(int cur, int max, int target) {
    if (target == 1) return cur;
    target--;
    int s = cur * 10;
    int e = s + 9;
    if (s == 0) {
        s = 1;
        e = 9;
    }
    int index = -1;
    int last_sum = 0;
    int sum = 0;
    for (int i = s; i <= e; i++) {
        last_sum = sum;
        sum += sub_tree_size(i, max);
        if (sum >= target) {
            index = i;
            break;
        }
    }
    return find(index, max, target - last_sum);
}

int findKthNumber(int n, int k) { return find(0, n, k + 1); }

int main() {
    dbg(findKthNumber(10000, 481));
    return 0;
}