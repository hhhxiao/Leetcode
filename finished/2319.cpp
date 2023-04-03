#include <vector>
using namespace std;

bool checkXMatrix(vector<vector<int>>& grid) {
    int row = grid.size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            int v = grid[i][j];
            if (i == j || i + j == row - 1) {
                if (v == 0) return false;
            } else {
                if (v != 0) return false;
            }
        }
    }
    return true;
}
