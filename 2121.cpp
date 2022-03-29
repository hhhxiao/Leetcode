#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
#include "dbg.h"

vector<long long> getDistances(vector<int>& arr) {
    /*
    a1 a2 .... an

    |ai - a0| + |ai - a1| + .... + |ai - an| =
    ai * i - (a1 + a2 + ... + a(i-1))

    + [(ai+1 + .... + an) - ai * (n - i- 1)]

    = (ai+1 + .... + an) - (a1 +.... + a[i-1]) + (2i +1 - n)*ai

    i - n + i + 1

    2 3 6
    2: (3+6) + (2*0 + 1 - 3) * 2 = 9 + (-4) = 5
    3  (6-2) + (2*1 + 1 - 3) * 3 = 4 + (0) = 4
    6  (-2-3) + (2*2 + 1- 3) * 6 = 12-5 = 7

    */
    std::vector<long long> res(arr.size(), 0);
    std::unordered_map<int, std::vector<int>> table;
    for (int i = 0; i < arr.size(); i++) {
        table[arr[i]].push_back(i);
    }

    for (auto& kv : table) {
        std::vector<int> prefix(1, 0);
        int sum = 0;
        for (auto ele : kv.second) {
            sum += ele;
            prefix.push_back(sum);
        }
        for (int i = 0; i < kv.second.size(); i++) {
            int a = sum - prefix[i + 1] - prefix[i];
            int r = (2 * i + 1 - kv.second.size()) * (kv.second[i]);
            res[kv.second[i]] = a + r;
        }
    }

    return res;
}

int main() {
    std::vector<int> res = {2, 2, 1, 1, 2, 2, 1};
    dbg(getDistances(res));
    return 0;
}