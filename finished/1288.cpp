#include <iostream>
#include <map>
#include <set>
#include <vector>

#include "dbg.h"

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals.size();
    std::sort(intervals.begin(), intervals.end(),
              [](const vector<int>& a, const vector<int>& b) {
                  if (a[0] >= b[0] && a[1] <= b[1]) return true;
                  if (a[0] <= b[0] && a[1] >= b[1]) return false;
                  return a[0] < b[0];
              });

    auto idx = intervals.size() - 1;

    int cover = 0;
    for (int i = intervals.size() - 2; i >= 0; i--) {
        auto& p = intervals[i];
        //被包含了
        if (p[0] >= intervals[idx][0] && p[1] <= intervals[idx][1]) {
            printf("[%d, %d] was covered by [%d,%d]\n", p[0], p[1],
                   intervals[idx][0], intervals[idx][1]);
            cover++;
        } else {
            idx = i;
        }
    }

    return intervals.size() - cover;
}

int main() {
    std::vector<std::vector<int>> v = {{1, 5}, {2, 6}, {3, 4}, {0, 8}};
    removeCoveredIntervals(v);
    printf("finish\n");
    return 0;
}
