#include <cmath>
#include <vector>

#include "dbg.h"

using namespace std;
long long maxPoints(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    std::vector<int> dp = points[0];

    for (int i = 1; i < points.size(); i++) {
        dbg(dp);
        auto& current_line = points[i];
        std::vector<int> temp;
        for (int j = 0; j < current_line.size(); j++) {
            int max = INT32_MIN;
            for (int k = 0; k < current_line.size(); k++) {
                int val = current_line[j] + dp[k] - abs(k - j);
                if (max < val) max = val;
            }
            temp.push_back(max);
        }
        dp = temp;
    }

    int max = dp[0];

    for (int i = 1; i < dp.size(); i++) {
        if (max < dp[i]) max = dp[i];
    }
    return max;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    std::cout << maxPoints(v);
    return 0;
}