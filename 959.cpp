#include <queue>
#include <string>
#include <vector>

using namespace std;
int regionsBySlashes(vector<string>& grid) {
    std::vector<std::vector<int>> visited;

    std::pair<int, int> init_seed = {0, 0};

    std::queue<std::pair<int, int>> seed_queue;
    seed_queue.push(init_seed);
    while (!seed_queue.empty()) {
        auto seed = seed_queue.front();
        seed_queue.pop();
        std::queue<std::pair<int, int>> bfs_queue;
        bfs_queue.push(seed);
        while (!bfs_queue.empty()) {
            
        }
    }
}

int main(int argc, char const* argv[]) { return 0; }
