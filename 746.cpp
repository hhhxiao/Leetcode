#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
//动态规划，走楼梯问题
//[1 2 3 4 5 6 7]
/*
要到达第i个楼梯的代价位F(i)
F(0) = 0
F(1) = 0

F(2)_1 = F(0) + a[0]
F(2)_1  =F(1) + a[1]

F(3)_1 = F(1) + a[1]
F(3)_2 = F(2) + a[2]

==>
F(0),F(1)
F(i) = min(F(i-2)+a[i-2],F(i-1)+a[i-1])

*/

int minCostClimbingStairs(vector<int>& cost) {
    int f[2] = {0, 0};
    int index = 0;
    int res = 0;
    for (int i = 2; i < cost.size(); i++) {
        int c1 = f[index] + cost[i - 2];
        int c2 = f[(index + 1) % 2] + cost[i - 1];
        f[index] = c1 > c2 ? c2 : c1;
        res = f[index];
        dbg(f[index]);
        index = (index + 1) % 2;
    }

    return res;
}
int main() {
    std::vector<int> v1 = {1, 100, 1, 1, 1000, 2, 1, 100};
    minCostClimbingStairs(v1);
    return 0;
}
