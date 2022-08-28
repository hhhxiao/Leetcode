#include <cmath>
#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
class Solution {
   public:
    double r;
    double x;
    double y;
    Solution(double radius, double x_center, double y_center) {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
    }
    vector<double> randPoint() {
        auto rtheta = (double)rand() * 2.925836078651066e-8;
        auto rr = (double)rand() * (r * r) / RAND_MAX;
        auto sr = sqrt(rr);
        auto dx = cos(rtheta) * sr;
        auto dy = sin(rtheta) * sr;
        return {dx + x, dy + y};
    }
};

int main() {
    Solution s(1.0, 0.0, 0.0);
    for (int i = 0; i < 10; i++) {
        s.randPoint();
    }
    return 0;
}
