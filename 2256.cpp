#include "a.h"
using namespace std;
int minimumAverageDifference(vector<int>& nums) {
    vector<int> prefix;
    prefix.reserve(nums.size());
    int sum = 0;
    for (auto i : nums) {
        sum += i;
        prefix.push_back(sum);
    }
    dbg(sum);
    dbg(prefix);
    int n = INT32_MAX;
    int index = -1;
    for (int i = 0; i < nums.size() - 1; i++) {
        int x = abs(int(prefix[i] / (i + 1) - (prefix.back() - prefix[i]) / (prefix.size() - i - 1)));
        if (n > x) {
            n = x;
            index = i;
        }
    }

    if (n > abs((int)(prefix.back() / prefix.size()))) {
        index = nums.size() - 1;
    }
    return index;
}
int main() {
    vector v{0};
    dbg(minimumAverageDifference(v));
    return 0;
}