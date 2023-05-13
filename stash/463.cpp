#include <iostream>
#include <vector>
using namespace std;
int islandPerimeter(vector<vector<int>>& grid) {
    int edge = 0;
    static int dx[] = {1, -1, 0, 0};
    static int dy[] = {0, 0, 1, -1};
    auto row = grid.size();
    auto col = grid[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                for (int n = 0; n < 4; n++) {
                    auto nx = i + dx[n];
                    auto ny = j + dy[n];
                    if (nx < 0 || nx >= row || ny < 0 || nx >= col) {
                        edge++;
                    } else {
                        edge += grid[nx][ny] == 1 ? 0 : 1;
                    }
                }
            }
        }
    }
    return edge;
}
int main(int argc, char const* argv[]) { return 0; }
