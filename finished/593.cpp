#include <iostream>
#include <utility>
#include <vector>

using namespace std;
/*



*/

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                 vector<int>& p4) {
    typedef pair<int, int> Vec;
    Vec v12 = {p2[0] - p1[0], p2[1] - p1[1]};
    Vec v13 = {p3[0] - p1[0], p3[1] - p1[1]};
    Vec v14 = {p4[0] - p1[0], p4[1] - p1[1]};
    int dot_1213 = v12.first * v13.first + v12.second * v13.second;
    int dot_1214 = v12.first * v14.first + v12.second * v14.second;
    int dot_1314 = v13.first * v14.first + v13.second * v14.second;
    /*
         / 12
        /
        -----  14
        \
         \ 12
    */
    Vec center{0, 0};
    Vec edge1{0, 0};
    Vec edge2{0, 0};
    if (dot_1213 == 0) {
        edge1 = v12;
        edge2 = v13;
        center = v14;
    } else if (dot_1214 == 0) {
        edge1 = v12;
        edge2 = v14;
        center = v13;
    } else if (dot_1314 == 0) {
        edge1 = v13;
        edge2 = v14;
        center = v12;
    } else {
        return false;
    }
    return center.first * edge1.first + center.second * edge1.second ==
               edge1.first * edge1.first + edge1.second * edge1.second &&
           center.first * edge2.first + center.second * edge2.second ==
               edge2.first * edge2.first + edge2.second * edge2.second;
}
