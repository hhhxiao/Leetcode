#include <cstdio>
#include <vector>

#include "dbg.h"

using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    std::vector<pair<int, int>> stack;

    std::vector<int> res(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
        int x = temperatures[i];
        while (!stack.empty() && stack.back().first < x) {
            printf("%d < %d\n", stack.back().first, x);
            res[stack.back().second] = i - stack.back().second;
            stack.pop_back();
        }
        stack.push_back({x, i});
    }
    return res;
}

int main() {
    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
    dbg(dailyTemperatures(v));
}