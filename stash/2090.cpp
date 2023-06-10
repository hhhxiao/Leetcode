#include <vector>

#include "a.h"

using namespace std;

#define ll long long
vector<int> getAverages(vector<int>& nums, int k) {
    vector<ll> pf;
    ll sum = 0ull;
    for (auto i : nums) {
        sum += i;
        pf.push_back(sum);
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int f = i - k;
        int e = i + k;
        if (f < 0 || e >= nums.size()) {
            res.push_back(-1);
        } else {
            res.push_back(f == 0 ? (int)(pf[e] / (2 * k + 1)) : (int)((pf[e] - pf[f - 1]) / (2 * k + 1)));
        }
    }
    return res;
}

int main() {
    vector<int> v{1000};
    dbg(getAverages(v, 100));
    return 0;
}
