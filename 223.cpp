#include "dbg.h"

struct Rec {
    int x1;
    int y1;
    int x2;
    int y2;

    int con(int x, int y) { return (x1 < x && x < x2 && y1 < y && y < y2) ? 1 : 0; }
    bool containPoint(const Rec& r) { return con(r.x1, r.y1) + con(r.x1, r.y2) + con(r.x2, r.y1) + con(r.x2, r.y2); }

    int area() { return abs(x1 - x2) * abs(y1 - y2); }
};
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    Rec r1{ax1, ay1, ax2, ay2};
    Rec r2{bx1, by1, bx2, by2};
    int c12 = r1.containPoint(r2);
    int c21 = r2.containPoint(r1);

    if (c12 == 0 && c21 == 0) {
        return r1.area() + r2.area();
    }
    if (c12 == 0 && c21 == 4) {
        return r2.area();
    }
    if (c12 == 4 && c21 == 0) {
        return r1.area();
    }

    // 重叠计算
    if (c12 == 2 && c21 == 0) {
    }
    if (c12 == 0 && c21 == 2) {
    }

    return 1;
}