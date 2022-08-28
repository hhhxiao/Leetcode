#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

int binarySearch(const vector<vector<int>>& matrix, int x, int col, int low,
                 int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (matrix[mid][col] == x) return mid;
        if (matrix[mid][col] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix[0][0] > target) return false;
    if (matrix.back().back() < target) return false;
    auto it = std::upper_bound(matrix[0].begin(), matrix[0].end(), target);
    int index = std::distance(matrix[0].begin(), it);
    printf("index = %d", index);
    int row = matrix[0].size();
    for (int i = 0; i < index; i++) {
        if (matrix[0][index] == target || matrix[row - 1][index] == target)
            return true;
        if (matrix[row - 1][index] < target) continue;
        if (binarySearch(matrix, target, index, 0, row - 1) != -1) {
            return true;
        } else {
            continue;
        }
    }
    return false;
}

int main() {
    auto v = std::vector<std::vector<int>>{{1, 2}, {3, 4}};
    searchMatrix(v, 3);
}