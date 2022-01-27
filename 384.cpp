#include <algorithm>
#include <random>
#include <vector>

using namespace std;

class Solution {
    std::vector<int> data_;

   public:
    Solution(vector<int>& nums) { this->data_ = nums; }

    vector<int> reset() { return this->data_; }
    vector<int> shuffle() {
        static std::random_device rd;
        static std::mt19937 g(rd());
        auto res = this->data_;
        std::shuffle(res.begin(), res.end(), g);
        return res;
    }
};

int main(int argc, char const* argv[]) { return 0; }
