#include <vector>

using namespace std;
vector<int> countPoints(vector<vector<int>>& points,
                        vector<vector<int>>& queries) {
    std::vector<int> buffer(queries.size(), 0);
    for (int i = 0; i < queries.size(); i++) {
        buffer[i] = queries[i][2] * queries[i][2];
    }

    for (int i = 0; i < queries.size(); i++) {
        int sum = 0;
        for (int j = 0; j < points.size(); j++) {
            int dx = points[j][0] - queries[i][0];
            int dy = points[j][1] - queries[i][1];
            if (dx * dx + dy * dy <= buffer[i]) {
                sum++;
            }
        }
        buffer[i] = sum;
    }
    return buffer;
}
