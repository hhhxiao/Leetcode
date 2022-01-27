#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int maxWidthOfVerticalArea(vector<vector<int>> &points) {
    std::sort(points.begin(), points.end(),
              [](const std::vector<int> &l, const std::vector<int> &r) {
                  return l[0] < r[0];
              });
    int res = INT32_MIN;
    for (int i = 1; i < points.size(); i++) {
        int w = points[i][0] - points[i - 1][0];
        if (res < w) res = w;
    }
    return res;
}