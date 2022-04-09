#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

int64_t fetch_num(const std::vector<int> &v, int begin, int sz) {
    int64_t sum = 0;
    for (int i = 0; i < sz; i++) {
        if (begin + i >= v.size()) {
            return sum;
        }
        sum *= 10L;
        sum += v[begin + i];
    }

    return sum;
}

void bt(std::vector<int> &cur, int index, const std::vector<int> &nums,
        std::vector<int> &res) {
    static int max_bits = nums.size() / 3 + 1;
    if (max_bits >= 12) max_bits = 12;
    if (index >= nums.size()) {
        if (cur.size() >= 3) {
            res = cur;
        }

        return;
    }

    for (int i = 1; i <= max_bits; i++) {
        int64_t num = fetch_num(nums, index, i);
        if (!(num != 0 && nums[index] == 0) && num <= INT32_MAX) {
            if (cur.size() <= 1 ||
                (cur.size() > 1 && num == (int64_t)cur[cur.size() - 1] +
                                              (int64_t)cur[cur.size() - 2])

            ) {
                cur.push_back((int)num);
                for (int j = 0; j < cur.size(); j++) {
                    printf("%d ", cur[j]);
                }
                printf(" idx = %d \n", index + i);
                bt(cur, index + i, nums, res);
                cur.pop_back();
            }
        }
    }
}
vector<int> splitIntoFibonacci(const string &num) {
    std::vector<int> nums(num.size(), 0);
    int n = 0;
    for (int i = 0; i < num.size(); i++) {
        nums[i] = num[i] - '0';
        if (nums[i] == 0) {
            n++;
        }
    }
    if (n == nums.size()) return nums;
    std::vector<int> cur;
    std::vector<int> res;
    bt(cur, 0, nums, res);
    dbg(res);
    return res;
}

int main() {
    const std::string s = "549132235579214924139063110211652267343256998";
    splitIntoFibonacci(s);

    return 0;
}
