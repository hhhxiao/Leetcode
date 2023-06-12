#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;
string smallestString(string s) {
    int i = 0;
    while (i < s.size() && s[i] == 'a') i++;
    if (i >= s.size()) {
        s[s.size() - 1] = 'z';
        return s;
    }

    while (i < s.size()) {
        if (s[i] == 'a') break;
        s[i] = (s[i] - 1);
        i++;
    }
    return s;
}

struct S {
    int a;
    int b;
    int sum;
    int i;
};

vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
    vector<S> d;
    for (int i = 0; i < nums1.size(); i++) {
        d.push_back({nums1[i], nums2[i], nums1[i] + nums2[i], i});
    }
    std::sort(d.begin(), d.end(), [](const S& a, const S& b) { return a.sum > b.sum; });
    vector<int> res;
    for (auto& q : queries) {
        int begin = 0;

        bool success = false;
        while (begin < d.size()) {
            auto& c = d[begin];
            if (c.a >= q[0] && c.b >= q[1]) {
                success = true;
                break;
            }
            begin++;
        }
        if (success) {
            res.push_back(d[begin].sum);
        } else {
            res.push_back(-1);
        }
    }

    return res;
}

int main() {
std:
    vector<int> n1{2, 1};
    vector<int> n2{2, 3};
    vector<vector<int>> qs{{4, 1}, {3, 3}, {2, 5}};
    dbg(maximumSumQueries(n1, n2, qs));

    return 0;
}