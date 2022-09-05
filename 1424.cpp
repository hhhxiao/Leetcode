#include <vector>

#include "dbg.h"

using namespace std;
// struct Pos {
//     int row;
//     int col;
//     bool operator<(const Pos& r) const {
//         int ts = row + col;
//         int rs = r.row + r.col;
//         if (ts != rs) return ts < rs;
//         return col < r.col;
//     }
//     bool operator==(const Pos& r) const { return r.col == col && r.row ==
//     row; }
// };

vector<int> findDiagonalOrder2(vector<vector<int>>& nums) {
    if (nums.empty()) return {};
    std::vector<int> res;

    struct Data {
        int row;
        int col;
        int value;
    };

    std::vector<Data> v;
    for (int row = 0; row < nums.size(); row++) {
        auto& line = nums[row];
        for (int col = 0; col < line.size(); col++) {
            Data d{row, col, line[col]};
            v.push_back(d);
        }
    }

    std::sort(v.begin(), v.end(), [](const Data& t, const Data r) {
        int ts = t.row + t.col;
        int rs = r.row + r.col;
        if (ts != rs) return ts < rs;
        return t.col < r.col;
    });

    for (auto& c : v) {
        res.push_back(c.value);
    }
    return res;
}

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    if (nums.empty()) return {};
    int maxLen = nums[0].size();
    for (auto& line : nums) {
        if (maxLen < line.size()) maxLen = line.size();
    }

    std::vector<int> res;
    //  dbg(maxLen);
    //左上
    for (int i = 0; i < nums.size(); i++) {
        for (int row = i; row >= 0; row--) {
            int col = i - row;
            if (nums[row].size() > col) {
                // dbg(nums[row][col]);
                res.push_back(nums[row][col]);
            }
        }
    }
    // dbg("====Split====");
    //右下半区
    for (int i = 1; i < maxLen; i++) {
        for (int row = nums.size() - 1; row >= 0; row--) {
            int col = i + nums.size() - row - 1;
            if (nums[row].size() > col) {
                // dbg(nums[row][col]);
                res.push_back(nums[row][col]);
            }
        }
    }
    return res;
}

int main() { /*clang-format off*/
    vector<vector<int>> v{{1, 2, 3}, {4}, {5, 6, 7}, {8}, {9, 10, 11}};

    findDiagonalOrder2(v);
}
