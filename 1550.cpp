#include <vector>
using namespace std;
bool threeConsecutiveOdds(vector<int>& arr) {
    int ctr = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1) {
            if (ctr == 2) return true;
            ctr++;
        } else {
            ctr = 0;
        }
    }
    return false;
}
