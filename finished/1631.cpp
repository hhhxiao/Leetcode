#include <vector>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
    int row = heights.size();
    int col = heights[0].size();
    std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));
}
