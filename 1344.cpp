#include <iostream>
double angleClock(int hour, int minutes) {
    int min = minutes * 6;
    int hour = hour * 30 + static_cast<double>(minutes) / 2;
    double res = fabs(min + 360.0 - hour);
    if (res > 360) res -= 360;
    return res > 180 ? 360 - res : res;
}

int main(int argc, char const *argv[]) { return 0; }
