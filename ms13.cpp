#include <vector>
using namespace std;
#include "dbg.h"
int getS(int c) {
    int res = 0;
    while (c > 0) {
        res += c % 10;
        c /= 10;
    }
    return res;
}

void bfs(std::vector<std::vector<int>>& flags, int m, int n, int k, int& res) {
    res++;
    flags[m][n] = 1;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + m;
        int ny = dy[i] + n;
        if (nx >= 0 && nx < flags.size() && ny >= 0 && ny < flags[0].size()) {
            if (flags[nx][ny] == 0 && getS(nx) + getS(ny) <= k) {
                bfs(flags, nx, ny, k, res);
            }
        }
    }
}
int movingCount(int m, int n, int k) {
    std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));
    //访问过了 1
    //没访问过 0
    int res = 0;
    bfs(v, 0, 0, k, res);

    return res;
}

int main() {
    dbg(movingCount(20, 20, 10));
    return 0;
}