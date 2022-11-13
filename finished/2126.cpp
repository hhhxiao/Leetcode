#include <algorithm>
#include <cstdio>
#include <vector>

#include "dbg.h"

using namespace std;
bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    std::sort(asteroids.begin(), asteroids.end());
    //  dbg(asteroids);
    int index = 0;
    while (index < asteroids.size() && mass >= asteroids[index]) {
        mass += asteroids[index];
        index++;
    }

    return index >= asteroids.size();
}

int main() {
    std::vector<int> v = {3, 4, 1, 4, 65, 7, 1, 2, 1};
    asteroidsDestroyed(2, v);

    return 0;
}
