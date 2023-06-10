#include <vector>
using namespace std;
class NumMatrix {
    vector<vector<int>> pf;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        pf = vector<vector<int>>(row, vector<int>(col, 0));
        // 计算前缀和
        int sum = 0;
        for (int i = 0; i < row; i++) {
            sum += matrix[i][0];
            pf[i][0] = sum;
        }

        sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[0][j];
            pf[0][j] = sum;
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                pf[i][j] = pf[i - 1][j] + pf[i][j - 1] + matrix[i][j] - pf[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return pf[row2][col2] + pf[row1][col1] - pf[row1][col2] - pf[row2][col1];
    }
};
