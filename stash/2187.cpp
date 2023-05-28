#include <iostream>
using namespace std;
#include <vector>

long long minimumTime(vector<int>& time, int totalTrips) {
    // 找到数组[x1,x2,....xn]
    // 满足约束 X1 + x2 + .... + xn = total

    // 且 max(xi * times i) 最小
    // 求 该最小值
    // T(idx,total) = min(times[idx]留0个的最小值,，time[idx ]留下1个的最小值，time[idx-1]留下2个的最小值)

    return 0;
}
