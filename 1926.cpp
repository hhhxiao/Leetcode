#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
int nearestExit(const vector<vector<char>>& maze, const vector<int>& entrance) {
    int min = 100000;
    int row = maze.size();
    int col = maze[0].size();
    vector<vector<short>> visited(row, vector<short>(col, 0));
    visited[entrance[0]][entrance[1]] = 1;
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        auto distance = visited[front.first][front.second];
        static int dx[] = {0, 0, 1, -1};
        static int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            auto nX = front.first + dx[i];
            auto nY = front.second + dy[i];
            if (nX >= 0 && nX < row && nY >= 0 && nY < col) {
                if (maze[nX][nY] == '.' && visited[nX][nY] == 0) {
                    visited[nX][nY] = distance + 1;
                    q.push({nX, nY});
                    if (nX == 0 || nX == row - 1 || nY == 0 || nY == col - 1) {
                        if (min > distance) {
                            min = distance;
                        }
                    }
                }
            }
        }
    }

    return min == 100000 ? -1 : min;
}
int main(int argc, char const* argv[]) {
    std::vector<std::vector<char>> mz = {

        {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}

    };

    nearestExit(mz, {1, 2});
    return 0;
}
