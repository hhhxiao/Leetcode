#include <algorithm>
#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;

struct UnionSet {
    std::vector<int> fa;
    UnionSet(int n) {
        fa = std::vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        if (x != fa[x]) fa[x] = find(fa[x]);
        return fa[x];
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
};

int arrayNesting(vector<int>& nums) {
    UnionSet u(nums.size());
    for (int i = 0; i < nums.size(); i++) u.unionSet(nums[i], nums[nums[i]]);
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[u.find(nums[i])]++;
    }

    return std::max_element(map.begin(), map.end(),
                            [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
                                return p1.second < p2.second;
                            })
        ->second;
}
int main() {
    vector<int> v{5, 4, 0, 3, 1, 6, 2};
    dbg(arrayNesting(v));
    return 0;
}
