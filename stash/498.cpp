#include <vector>
using namespace std;

bool valid(int x, int y, int r, int c) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int r = mat.size();
    int c = mat[0].size();
    int dir = 1;  //右上；
    int x = 0, y = 0;
    while (x != mat.size() || y != mat[0].size()) {
        res.push_back(mat[x][y]);
        if (dir == 1) {
            x--;
            y++;
            bool needChange = false;
            if (!valid(x, y, r, c)) {
                x++;
                needChange = true;
            }
            if (!valid(x, y, r, c)) {
                x--;
                y++;
                needChange = true;
            }
            if (needChange) {
                dir = 0;
            }
        } else if (dir == 0) {
            x++;
            y--;
            bool needChange = false;
            if (!valid(x, y, r, c)) {
                y++;
                needChange = true;
            }
            if (!valid(x, y, r, c)) {
                x++;
                y--;
            }
            if (needChange) {
                dir = 1;
            }
        }
    }

    return res;
}