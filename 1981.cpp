#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    std::unordered_set<int> s;
    s.insert(target);
    int min = INT32_MAX;
    std::vector<int> diffs;

    for (int i = 0; i < mat.size(); i++) {
        auto row = mat[i];
        std::unordered_set<int> new_set;
        int max_neg = INT32_MIN;
        for (int j = 0; j < row.size(); j++) {
            for (auto& target : s) {
                //计算diff
                int diff = target - row[j];
                if (i == mat.size() - 1) {
                    int abs_d = abs(diff);
                    if (min > abs_d) {
                        min = abs_d;
                    }
                } else {
                    if (diff < 0) {
                        if (max_neg < diff) max_neg = diff;
                    } else {
                        new_set.insert(diff);
                    }
                }
            }
        }
        s = new_set;
        if (max_neg != INT32_MIN) s.insert(max_neg);
    }
    return min;
}

int main(int argc, char const* argv[]) { return 0; }
