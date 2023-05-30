#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
std::vector<int> get_path(int x) {
    vector<int> p(1, x);
    while (x > 1) {
        x /= 2;
        p.push_back(x);
    }
    return p;
}
int len(int x, int y) {
    auto px = get_path(x);
    auto py = get_path(y);
    // px x 1x..12131 1
    // pz dsds 1
    int index = 0;
    while (index < px.size() && index < py.size() && px[px.size() - index - 1] == py[py.size() - 1 - index]) index++;
    int dx = px.size() - index;
    int dy = py.size() - index;
    dbg(dx);
    dbg(dy);
    return dx + dy + 1;
}

vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> v;
    for (auto& q : queries) {
        v.push_back(len(q[0], q[1]));
    }

    return v;
}

int main() {
    len(4, 2);
    return 0;
}