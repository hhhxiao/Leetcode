#include <cstddef>
#include <vector>
using namespace std;
uint16_t tb[1000001];
vector<int> findLonely(vector<int>& nums) {
    memset(tb, 0, sizeof(uint16_t) * 1000001);
    for (int i = 0; i < nums.size(); i++) {
        tb[nums[i]]++;
    }
    std::vector<int> res;

    if (tb[0] == 1 && tb[1] == 0) {
        res.push_back(0);
    }
    if (tb[1000000] == 1 && tb[999999] == 0) {
        res.push_back(1000000);
    }

    for (int i = 1; i < 1000000; i++) {
        if (tb[i] == 1 && tb[i - 1] == 0 && tb[i + 1] == 0) {
            res.push_back(i);
        }
    }
    return res;
}
