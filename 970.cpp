#include <vector>
using namespace std;
#include "dbg.h"
vector<int> powerfulIntegers(int x, int y, int bound) {
    std::vector<int> res;
    std::unordered_set<int> s;
    std::vector<int> ax;
    std::vector<int> ay;
    int mul = 1;
    if (x != 1) {
        while (mul < bound) {
            ax.push_back(mul);
            mul *= x;
        }
    } else {
        ax.push_back(1);
    }

    mul = 1;
    if (y != 1) {
        while (mul < bound) {
            ay.push_back(mul);
            mul *= y;
        }
    } else {
        ay.push_back(1);
    }

    for (int i = 0; i < ax.size(); i++) {
        int remain = bound - ax[i];
        int idx = 0;
        while (idx < ay.size() && ay[idx] <= remain) {
            s.insert(ax[i] + ay[idx]);
            idx++;
        }
    }

    for (auto e : s) res.push_back(e);
    return res;
}

int main() { dbg(powerfulIntegers(3, 2, 10000)); }