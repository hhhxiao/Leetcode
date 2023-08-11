#include <stdio.h>

#include <map>
#include <vector>

#include "a.h"

using namespace std;

pair<int, int> go(int x, int y, vector<vector<int>>& v) {
    // 构建连接关系表
    // 上 0
    // 下 1
    // 左 2
    // 右 3
    enum Dir { Up = 0, Down = 1, Left = 2, Right = 3 };

    vector<vector<Dir>> to{
        {},             // 0
        {Left, Right},  // 1
        {Up, Down},     // 2
        {Left, Down},   // 3
        {Right, Down},  // 4
        {Left, Up},     // 5
        {Right, Up},    // 6
    };

    // vector<vector<Dir>> accept{
    //     {},             // 0
    //     {Left, Right},  // 1
    //     {Up, Down},     // 2
    //     {Right, Down},  // 3
    //     {Right, Down},  // 4
    //     {Left, Up},     // 5
    //     {Right, Up},    // 6
    // };

    // printf("%d ~ %d --> %d\n", x, y, v[x][y]);
    // auto nxs = nexts[v[x][y]];
}
bool hasValidPath(vector<vector<int>>& grid) {
    pair<int, int> cur;
    while (true) {
    }
    return true;
}
