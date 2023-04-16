#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    std::vector<int> t;
    Solution(vector<int>& w) {
        int sum = 0;
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            t.push_back(sum);
        }
    }

    int pickIndex() {
        auto it = std::lower_bound(t.begin(), t.end(), rand() % t.back());
        return it - t.begin();
    }
};

int main() {
    std::vector<int> v{1, 2};
    Solution s(v);
    for (int i = 0; i < 100; i++) {
        std::cout << s.pickIndex() << " ";
    }
}
