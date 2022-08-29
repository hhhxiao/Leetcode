#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "dbg.h"

using namespace std;
class Solution {
   public:
    std::vector<int> acc;
    std::vector<int> weights;
    int sum = 0;
    Solution(vector<int>& w) {
        //累加和
        int sum = 0;

        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            acc.push_back(sum);
        }
        this->weights = w;
        dbg(weights);
        dbg(acc);
    }

    int pickIndex() {
        auto r = rand() % acc.back();
        auto it = std::upper_bound(acc.begin(), acc.end(), r);
        auto d = std::distance(acc.begin(), it);
        printf("r = %d, choose %d\n", r, this->weights[d]);
        return this->weights[d];
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4};
    Solution s(v);
    for (int i = 0; i < 20; i++) {
        s.pickIndex();
    }
}
