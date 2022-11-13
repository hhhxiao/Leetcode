#include <cstdio>
#include <vector>

using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    int pp = 0;
    int pn = 0;
    std::vector<int> res;
    while (res.size() < nums.size()) {
        printf("pp = %d pn = %d\n", pp, pn);
        while (nums[pp] < 0) {
            pp += 1;
        }

        res.push_back(nums[pp]);
        while (nums[pn] > 0) {
            pn += 1;
        }
        res.push_back(nums[pn]);
        pp++;
        pn++;
    }
    return res;
}
int main() {
    std::vector<int> res = {3, 1, -2, -5, 2, -4};
    rearrangeArray(res);
    return 0;
}
