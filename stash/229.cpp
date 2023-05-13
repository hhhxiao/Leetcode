#include <unordered_map>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }
    std::vector<int> res;
    int limit = nums.size() / 3;
    for (auto& kv : map) {
        if (kv.second > limit) {
            res.push_back(kv.first);
        }
    }
    return res;
}
int main(int argc, char const* argv[]) { return 0; }
