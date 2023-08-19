#include <algorithm>
#include <iostream>
#include <vector>

#include "a.h"
using namespace std;
int trap(vector<int>& height) {
    if (height.size() <= 1) return 0;

    std::vector<int> left(height.size(), 0);
    std::vector<int> right(height.size(), 0);
    for (int i = 1; i < height.size(); i++) left[i] = std::max(height[i - 1], left[i - 1]);
    for (int i = height.size() - 2; i >= 0; i--) right[i] = std::max(height[i + 1], right[i + 1]);
    int res = 0;
    for (int i = 0; i < height.size(); i++)
        res += std::max(std::min(left[i], right[i]) - height[i], 0);
    return res;
}

int main() {
    vector v{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    dbg(trap(v));
    return 0;
}
