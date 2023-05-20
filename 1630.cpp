#include <algorithm>
#include <unordered_map>
#include <vector>

#define ALL(v) v.begin(), v.end()
#define FOR(i, size) for (int(i) = 0; (i) < (size); (i)++)

using namespace std;
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;

    FOR(i, l.size()) {
        auto sub = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
        if (sub.size() <= 1) {
            res.push_back(true);
            continue;
        }
        std::sort(ALL(sub));
        FOR(j, sub.size() - 1) {
            if (sub[j + 1] - sub[j] != sub[1] - sub[1]) {
                res.push_back(false);
                continue;
            }
        }

        res.push_back(true);
    }

    return res;
}