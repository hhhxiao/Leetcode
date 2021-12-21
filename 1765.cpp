#include <queue>
#include <vector>

#include "dbg.h"

using namespace std;

void bfs(vector<vector<int>>& mat, const pair<int, int>& seed) {
    vector<vector<int>> visit(mat.size(), vector<int>(mat[0].size(), 0));
    queue<pair<int, int>> q;
    q.push(seed);
    while (!q.empty()) {
        auto pos = q.front();
        q.pop();
        int val = mat[pos.first][pos.second];
        visit[pos.first][pos.second] = 1;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};
        int newVal = val + 1;
        for (int i = 0; i < 4; i++) {
            int nX = pos.first + dx[i];
            int nY = pos.second + dy[i];
            printf("[%d] [%d]: \n", nX, nY);
            if (nX >= 0 && nX < mat.size() && nY >= 0 && nY < mat[0].size() &&
                visit[nX][nY] == 0 && mat[nX][nY] != 0) {
                if (mat[nX][nY] > newVal) {
                    printf("val = %d\n", newVal);
                    mat[nX][nY] = newVal;
                    q.push({nX, nY});
                }
            }
        }
    }
}

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int row = isWater.size();
    int col = isWater[0].size();
    vector<pair<int, int>> seeds_list;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (isWater[i][j] == 1) {
                isWater[i][j] = 0;
                seeds_list.push_back({i, j});
            } else {
                isWater[i][j] = 10000;
            }
        }
    }

    for (int i = 0; i < seeds_list.size(); i++) {
        bfs(isWater, seeds_list[i]);
    }
    return isWater;
}

int main(int argc, char const* argv[]) {
    vector<vector<int>> v = {{0, 1}, {1, 0}};
    highestPeak(v);
    return 0;
}
