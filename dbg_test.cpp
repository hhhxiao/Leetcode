#include "dbg.h"

#include <unordered_map>
#include <vector>

int main() {
    const std::vector<std::unordered_map<int, int>> x{{{1, 1}, {2, 3}}, {{1, 3}, {3, 1}}};
    dbg(x);
    int arr[]{1, 2, 3};
    dbg(arr);
    return 0;
}
