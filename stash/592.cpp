#include <cassert>
#include <numeric>
#include <string>

#include "dbg.h"

using namespace std;

void add(int64_t ax, int64_t ay, int64_t bx, int64_t by, int64_t& x, int64_t& y) {
    auto t = ax * by + ay * bx;
    auto b = ay * by;
    auto g = std::gcd(t, b);
    x = t / g;
    y = b / g;
}

string fractionAddition(const string& expression) {
    auto e = expression[0] == '-' ? expression : "+" + expression;
    dbg(e);
    int i = 0;

    int64_t rx = 0;
    int64_t ry = 1;

    while (i < e.size()) {
        if (e[i] != '+' && e[i] != '-') {
            return "";
        }

        char c = e[i];
        int64_t sign = e[i] == '+' ? 1 : -1;
        i++;
        int64_t top = 0;
        while (i < e.size() && e[i] != '+' && e[i] != '-' && e[i] != '/') {
            top *= 10;
            top += (e[i] - '0');
            i++;
        }

        assert(e[i] == '/');
        i++;

        int64_t but = 0;
        while (i < e.size() && e[i] != '+' && e[i] != '-' && e[i] != '/') {
            but *= 10;
            but += (e[i] - '0');
            i++;
        }

        auto x = rx;
        auto y = ry;
        add(x, y, top * sign, but, rx, ry);
    }

    return std::to_string(rx) + "/" + std::to_string(ry);
}

int main() {
    dbg(fractionAddition("-1/4-3/6+1/6-1/10+12/13"));
    return 0;
}