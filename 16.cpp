/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
        1.两层for循环，计算a+b
        然后使用std::lower_bound()找到最接近的
        (可能可以剪枝优化)
        总的复杂度O(n^2logn)
        */

        std::map<int, int> m;
        //计数器
        for (int i = 0; i < nums.size(); i++) m[nums[i]]++;
        //删除冗余后的排序数组
        std::vector<int> u;
        for (auto& kv : m) {
            u.push_back(kv.first);
        }

        // i 三个一样的
        int cloest = 1000000000;
        int min_abs = cloest - target;
        for (auto& kv : m) {
            if (kv.second >= 3) {
                auto diff = abs(kv.first * 3 - target);
                if (diff == 0) return target;
                if (diff < min_abs) {
                    cloest = kv.first * 3;
                    min_abs = diff;
                }
            }
        }

        // printf("Same three closest = %d , abs = %d\n", cloest, min_abs);
        if (m.size() == 1) return cloest;
        // j 两个一样的
        for (auto& kv : m) {
            if (kv.second >= 2) {
                auto last = target - kv.first * 2;
                auto it = std::lower_bound(u.begin(), u.end(), last);
                int idx = it - u.begin();
                //  printf("find idx = %d\n", idx);
                for (int i = -1; i <= 1; i++) {
                    auto n = idx + i;
                    // printf("test %d\n", n);
                    if (n >= 0 && n < u.size() && u[n] != kv.first) {
                        int diff = abs(last - u[n]);
                        //       printf("diff = %d\n", diff);
                        if (diff == 0) return target;
                        if (diff < min_abs) {
                            cloest = kv.first * 2 + u[n];
                            min_abs = diff;
                        }
                    }
                }
            }
        }
        // printf("Two + One closest = %d , abs = %d\n", cloest, min_abs);

        if (m.size() < 3) return cloest;
        //  // k三个都不一样

        for (int i = 0; i < u.size() - 2; i++) {
            for (int j = i + 1; j < u.size() - 1; j++) {
                //   printf("test %d %d  ", u[i], u[j]);
                int last = target - (u[i] + u[j]);
                auto it = std::lower_bound(u.begin() + j + 1, u.end(), last);
                int idx = it - u.begin();
                // printf("find u[%d]\n", idx);
                for (int x = -1; x <= 1; x++) {
                    auto n = idx + x;
                    //   printf("test %d\n", n);
                    if (n >= 0 && n < u.size() && n != i && n != j) {
                        int diff = abs(last - u[n]);
                        if (diff == 0) return target;
                        if (diff < min_abs) {
                            cloest = u[i] + u[j] + u[n];
                            min_abs = diff;
                        }
                    }
                }
            }
        }
        // printf("One + One + One closest = %d , abs = %d\n", cloest, min_abs);
        return cloest;
    }
};
// @lc code=end

int main() {
    std::vector<int> v{1, 1, 1, 0};
    Solution s;
    std::cout << s.threeSumClosest(v, -100) << std::endl;
    return 0;
}