#include <numeric>
#include <vector>

#include "dbg.h"

using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    const int T = threshold * k;
    int sum = std::accumulate(arr.begin(), arr.begin() + k, 0);
    int res = sum >= T ? 1 : 0;
    for (int i = 1; i <= arr.size() - k; i++) {
        sum += arr[i + k - 1];
        sum -= arr[i - 1];
        if (sum >= T) res++;
    }
    return res;
}

int main() {
    std::vector<int> v = {1, 3, 4, 5, 6, 1, 2, 3};
    numOfSubarrays(v, 4, 1);
    return 0;
}