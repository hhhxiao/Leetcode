#include <vector>

#include "dbg.h"

using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> x(n + 2, 0);
    for (auto& i : bookings) {
        int f = i[0];
        int e = i[1];
        x[f] += i[2];
        x[e + 1] -= i[2];
    }

    std::vector<int> res;
    int t = x[0];
    for (int i = 1; i < x.size() - 1; i++) {
        t += x[i];
        res.push_back(t);
    }
    return res;
}
int main() {
    vector<vector<int>> v{{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    corpFlightBookings(v, 5);
    return 0;
}
