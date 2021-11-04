#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
typedef std::pair<char, char> point_t;
int numIslands(vector<vector<char>>& grid) {
    const int row = grid.size();
    const int col = grid[0].size();
    int counter = 0;
    std::queue<point_t> seed_quene;
    seed_quene.emplace(0, 0);

    int off_x[] = {1, -1, 0, 0};
    int off_y[] = {0, 0, 1, -1};
    while (!seed_quene.empty()) {
        auto seed = seed_quene.front();
        seed_quene.pop();
        auto t = grid[seed.first][seed.second];
        if (t == 2) {
            continue;
        }

        if (t == 1) {
            ++counter;
        }
        // BFS here
        std::queue<point_t> q;
        q.push(seed);
        while (!q.empty()) {
            auto point = q.front();
            auto biome = grid[point.first][point.second];
            q.pop();
            for (int i = 0; i < 4; i++) {
                auto newX = off_x[i] + point.first;
                auto newY = off_y[i] + point.second;
                if (newX >= 0 && newX < row && newY >= 0 && newY < col) {
                    auto b = grid[newX][newY];
                    if (b != 2) {
                        if (b == biome) {
                            q.emplace(newX, newY);
                        } else {
                            seed_quene.emplace(newX, newY);
                        }
                    }
                }
            }
            grid[point.first][point.second] = 2;
        }
    }

    return counter;
}

int main(int argc, char const* argv[]) {
    std::vector<std::vector<char>> v = {
        {1, 1, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1}

    };
    numIslands(v);
    return 0;
}
