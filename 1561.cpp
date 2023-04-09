#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxCoins(vector<int>& piles) {
    std::sort(piles.begin(), piles.end());
    const int n = piles.size() / 3;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += piles.size() - i * 2 - 2;
    }
    return res;
}
