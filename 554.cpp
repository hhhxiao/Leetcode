#include <unordered_map>
#include <vector>

using namespace std;
int leastBricks(vector<vector<int>>& wall) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < wall.size(); i++) {
        auto& line = wall[i];
        int width = 0;
        for (int j = 0; j < line.size(); j++) {
            width += line[j];
            m[width]++;
        }
    }

    int min = m.begin()->second;
    for (auto& kv : m) {
        if (min > kv.second) {
            min = kv.second;
        }
    }
    return min;
}