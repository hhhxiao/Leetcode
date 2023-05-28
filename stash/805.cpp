#include <numeric>
#include <vector>

using namespace std;

#define va(x) x.begin(), x.end()

/**
 * 给定你一个整数数组 nums
我们要将 nums 数组中的每个元素移动到 A 数组 或者 B 数组中，使得 A 数组和 B 数组不为空，并且 average(A) == average(B) 。
如果可以完成则返回true ， 否则返回 false  。
来源：力扣（LeetCode）

sum(A) / len(A) = SUM / N
N * sum(A) = SUM * len

即从判定新数组NUM中是否存在X个数字,使得其和为SUM * X,且(1<=x < N)

记T(j,s) 表示子数组[0,j]中是否存在长度为s的子数组使得其和为


 *
*/

bool splitArraySameAverage(vector<int>& nums) {
    auto sum = std::accumulate(va(nums), 0);
    for (auto& i : nums) i *= nums.size();
}
