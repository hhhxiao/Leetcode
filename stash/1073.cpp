#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> add(const vector<int>& a, const vector<int>& b) {
    std::vector<int> res;
    int in = 0;
    for (int i = 0; i < a.size(); i++) {
        //
        int sum = in + a[i] + b[i];
        if (sum == 0 || sum == 1) {
            res.push_back(sum);
            in = 0;
        } else if (sum == 2) {
            in = -1;
            res.push_back(0);
        } else if (sum == -1) {
            in = 1;
            res.push_back(1);
        } else if (sum == 3) {
            in = -1;
            res.push_back(1);
        } else {
            printf("Unknown: Sum = %d", sum);
            return {};
        }
    }
    if (in == 1) {
        res.push_back(1);
    } else if (in == -1) {
        res.push_back(1);
        res.push_back(1);
    }
    return res;
}
vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    std::reverse(arr1.begin(), arr1.end());
    std::reverse(arr2.begin(), arr2.end());
    if (arr1.size() < arr2.size()) {
        std::swap(arr1, arr2);
    }
    arr2.resize(arr1.size());
    dbg(arr1);
    dbg(arr2);
    auto res = add(arr1, arr2);
    while (!res.empty() && res.back() == 0) res.pop_back();
    if (res.empty()) res.push_back(0);
    std::reverse(res.begin(), res.end());
    dbg(res);
    return res;
}
int main() {
    vector<int> v1{1, 0, 1};
    vector<int> v2{1, 0, 1};
    addNegabinary(v1, v2);
    return 0;
}