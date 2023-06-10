#include <stdint.h>

#include <unordered_map>
#include <vector>

#include "a.h"

using namespace std;
int longestWPI(vector<int>& hours) {
    vector<int> pf;
    pf.reserve(hours.size());
    pf.push_back(0);
    int sum = 0;
    for (int i = 0; i < hours.size(); i++) {
        sum += (hours[i] > 8 ? 1 : -1);
        pf.push_back(sum);
    }

    dbg(pf);

    int res = 0;

    return res;
}

int main() {
    std::vector<int> hs{9, 9, 6, 0, 6, 6, 9};
    dbg(longestWPI(hs));
    return 0;
}
