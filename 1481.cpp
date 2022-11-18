#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
int findLeastNumOfUniqueInts(const vector<int>& arr, int k) {
    if (k >= arr.size()) return 0;

    std::map<int, int> m;
    for (int i = 0; i < arr.size(); i++) {
        m[arr[i]]++;
    }
    //    dbg(m);

    std::map<int, std::vector<int>> ctr;
    for (auto& kv : m) {
        ctr[kv.second].push_back(kv.first);
    }

    //    dbg(ctr);
    while (k > 0 && !(ctr.empty())) {
        auto it = ctr.begin();
        auto total = it->second.size() * it->first;
        if (k >= total) {
            k -= total;
            ctr.erase(it);
        } else {
            int res = 0;
            for (auto& m : ctr) {
                res += m.second.size();
            }

            return res - k / it->first;
        }
    }

    // dbg(ctr);
    int res = 0;
    for (auto& m : ctr) {
        res += m.second.size();
    }

    return res;
}
int main() {
    //[2,4,1,8,3,5,1,3] 3
    dbg(findLeastNumOfUniqueInts({2, 4, 1, 8, 3, 5, 1, 3}, 3));
    return 0;
}