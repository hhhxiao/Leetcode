/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int64_t> stack;
        for (int i = 0; i < tokens.size(); i++) {
            auto& t = tokens[i];
            if (t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')) {
                auto s1 = stack.back();
                stack.pop_back();
                auto s2 = stack.back();
                auto res = 0ull;
                if (t[0] == '+') {
                    res = s2 + s1;
                } else if (t[0] == '-') {
                    res = s2 - s1;
                } else if (t[0] == '*') {
                    res = s2 * s1;
                } else if (t[0] == '/') {
                    res = s2 / s1;
                }
                ///   printf("%d %c %d = %d\n", s2, t[0], s1, res);
                stack[stack.size() - 1] = res;
            } else {
                stack.push_back(std::strtol(t.c_str(), nullptr, 10));
            }
        }
        return stack[0];
    }
};
// @lc code=end
