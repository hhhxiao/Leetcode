#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "a.h"

using namespace std;
vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
    long long sum1 = 0, sum2 = 0;
    for (auto i : array1) sum1 += i;

    std::unordered_multiset<int> s;
    for (auto i : array2) {
        sum2 += i;
        s.insert(i);
    }

    for (auto i : array1) {
        long long t2 = sum2 - sum1 + 2 * i;
        if (t2 % 2 != 0) continue;
        auto it = s.find(t2 / 2);
        if (it == s.end()) continue;
        return {i, (int)t2 / 2};
    }
    return {};
}
int main() {
    vector<int> v1 = {1, 2, 1, 1, 2};

    vector<int> v2 = {3, , 3, 3};

    dbg(findSwapValues(v1, v2));
    return 0;
}
