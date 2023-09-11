#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>

#include "a.h"

using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    std::vector<std::pair<int, int>> ps;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 1; j < arr.size(); j++) {
            ps.emplace_back(arr[i], arr[j]);
        }
    }
    std::sort(ps.begin(), ps.end(),
              [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                  return p1.first * p2.second < p1.second * p2.first;
              });
    // dbg(ps);

    return {ps[k - 1].first, ps[k - 1].second};
}

int main() {
    vector<int> v{1, 3, 5, 7};

    dbg(kthSmallestPrimeFraction(v, 2));

    return 0;
}
