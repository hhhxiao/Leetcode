#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 0) {
                for (int x = 0; x < row; x++) {
                    matrix[x][j] = 2;
                }
                for (int y = 0; y < col; y++) {
                    matrix[i][y] = 2;
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] == 2) {
                matrix[i][j] = 1;
            }
        }
    }
}
int main(int argc, char const* argv[]) { return 0; }
