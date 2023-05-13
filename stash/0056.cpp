#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

/**
 * [1 2] [2 3]
 *
 *
 */

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    std::sort(intervals.begin(), intervals.end(),
              [](const std::vector<int>& l, const std::vector<int>& r) {
                  return l[0] < r[0];
              });

    std::vector<std::vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        auto& current = intervals[i];
        auto& last = res[res.size() - 1];
        if (current[0] > last[1]) {
            res.push_back(current);
        } else if (current[0] == last[1]) {
            last[1] = current[1];
        } else if (current[0] >= last[0]) {
            last[1] = std::max(current[1], last[1]);
        }
    }
    return res;
}

int main(int argc, char const* argv[]) { return 0; }
