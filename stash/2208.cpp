#include <functional>
#include <numeric>
#include <queue>
#include <vector>

#include "a.h"

using namespace std;

int halveArray(vector<int>& nums) {
    std::priority_queue<double, std::vector<double>, std::less<double>> q;
    double sum = 0;
    for (auto i : nums) {
        auto d = static_cast<double>(i);
        sum += d;
        q.push(d);
    }

    double x = 0.0;
    int res = 0;
    while (x * 2 < sum) {
        auto top = q.top();
        q.pop();
        res++;
        auto half = top / 2.0;
        x += half;
        q.push(half);
        // dbg(top);
    }
    return res;
}

int main() {
    std::vector<int> v{3, 8, 20};
    dbg(halveArray(v));
    return 0;
}
