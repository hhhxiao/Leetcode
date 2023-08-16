#include <algorithm>
#include <iterator>
#include <numeric>
#include <system_error>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;
using ll = long long;
// long long matrixSumQueries(int n, vector<vector<int>>& queries) {
//     std::vector<ll> row(n, 0);
//     std::unordered_map<ll, ll> vs;
//     for (auto& q : queries) {
//         if (q[0] == 0) {
//             row[q[1]] = q[2];
//             for (int i = 0; i < n; i++) {
//                 vs.erase(q[1] * 10000ll + i);
//             }
//         } else if (q[0] == 1) {
//             for (int i = 0; i < n; i++) {
//                 if (row[i] != q[2]) {
//                     vs[i * 10000ll + q[1]] = q[2];
//                 }
//             }
//         }
//     }

//     ll sum = std::accumulate(row.begin(), row.end(), 0ll) * n;
//     for (auto kv : vs) {
//         ll r = kv.first / 10000ll;
//         ll c = kv.second % 10000ll;

//         sum += kv.second;
//         sum -= row[r];
//     }

//     return sum;
// }

long long matrixSumQueries(int n, vector<vector<int>>& queries) {
    std::set<int> r, c;
    ll sum{0};
    std::reverse(queries.begin(), queries.end());
    for (auto& q : queries) {
        if (q[0] == 0) {
            if (r.count(q[1]) == 0) {
                sum += (n - c.size()) * (ll)q[2];
                r.insert(q[1]);
            }

        } else {
            if (c.count(q[1]) == 0) {
                sum += (n - r.size()) * (ll)q[2];
                c.insert(q[1]);
            }
        }
    }
    return sum;
}

int main() {
    std::vector<std::vector<int>> queries = {{0, 0, 4}, {0, 1, 2}, {1, 0, 1}, {0, 2, 3}, {1, 2, 1}};
    dbg(matrixSumQueries(3, queries));

    return 0;
}