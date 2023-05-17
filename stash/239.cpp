#include <deque>
#include <vector>

#include "dbg.h"
// 单调队列

using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (k == 1) return nums;

    std::vector<int> res;
    std::deque<pair<int, int>> q;
    for (int i = 0; i < nums.size(); i++) {
        // 删除超过窗口阈值的元素
        while (!q.empty() && q.front().first + k <= i) {
            q.pop_front();
        }

        // 递减队列，队头永远的最大
        while (!q.empty() && q.back().second <= nums[i]) {
            q.pop_back();
        }

        q.push_back({i, nums[i]});
        if (i + 1 >= k) {
            res.push_back(q.front().second);
        }
    }

    return res;
}
int main() {
    std::vector<int> v{1, 3, 6, 7, 3, 2, 1, 5, 6, 4};
    dbg(maxSlidingWindow(v, 2));
    return 0;
}