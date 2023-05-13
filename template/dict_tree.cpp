#include <algorithm>
#include <cstdint>

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
