#include <algorithm>
#include <vector>
using namespace std;

int get_max(int v, std::vector<int>& array) {
    int max_h = max(array[0], v - array[array.size() - 1]);
    for (int i = 1; i < array.size(); i++) {
        auto d = array[i] - array[i - 1];
        if (max_h < d) {
            max_h = d;
        }
    }
}

int maxArea(int h, int w, vector<int>& horizontalCuts,
            vector<int>& verticalCuts) {
    return (static_cast<int64_t>(get_max(h, horizontalCuts)) *
            static_cast<int64_t>(get_max(w, verticalCuts))) %
           1000000007;
}
