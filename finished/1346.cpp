#include <unordered_set>
#include <vector>
using namespace std;
bool checkIfExist(vector<int>& arr) {
    bool checkIfExist(vector<int> & arr) {
        std::unordered_set<int> set;
        for (int i = 0; i < arr.size(); i++) {
            if (set.count(arr[i] * 2)) {
                return true;
            }
            if (arr[i] % 2 == 0) {
                if (set.count(arr[i] / 2)) {
                    return true;
                }
            }
            set.insert(arr[i]);
        }
        return false;
    }
}
