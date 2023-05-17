#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
// 两个方向同时计数
vector<int> minOperations(const string& boxes) {
    int balls = 0;
    int steps = 0;
    std::vector<int> res(boxes.size(), 0);
    for (int i = 0; i < boxes.size(); i++) {
        steps += balls;
        res[i] += steps;
        if (boxes[i] == '1') balls++;
    }

    balls = 0;
    steps = 0;

    for (int i = boxes.size() - 1; i >= 0; i--) {
        steps += balls;
        res[i] += steps;
        if (boxes[i] == '1') balls++;
    }

    return res;
}
int main() { minOperations("100011101"); }