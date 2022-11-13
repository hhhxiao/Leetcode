#include <iostream>
#include <vector>
using namespace std;
int maxProductPath(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> neg(rows, vector<int>(cols));
    vector<vector<int>> pos(rows, vector<int>(cols));
    if (grid[0][0] > 0) {
        neg[0][0] = INT32_MIN;
        pos[0][0] = grid[0][0];
    } else {
        neg[0][0] = grid[0][0];
        pos[0][0] = INT32_MAX;
    }

    for (int i = 1; i < cols; i++) {
        if (grid[0][i] == 0) {
            neg[0][i] = 0;
            pos[0][i] = 0;
        } else if (grid[0][i] > 0) {
            //+ - [+]
            if (pos[0][i - 1] == INT32_MAX) {
                pos[0][i] = INT32_MAX;
            } else {
            }
        } else if (grid[0][i] < 0) {
        }
    }
}
int main(int argc, char const* argv[]) { return 0; }
