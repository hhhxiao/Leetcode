#include <algorithm>
#include <map>
#include <vector>

#include "dbg.h"

using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
    std::map<int, int> map;
    for (size_t i = 0; i < hand.size(); i++) {
        map[hand[i]]++;
    }
    while (!map.empty()) {
        if (map.size() < groupSize) {
            return false;
        }

        dbg(map);
        auto iter = map.begin();
        int value = iter->first;
        int count = iter->second;
        iter->second = 0;
        for (int i = 0; i < groupSize - 1; i++) {
            std::advance(iter, 1);
            if (iter->first != value + 1) {
                return false;
            }
            if (iter->second < count) {
                return false;
            }
            iter->second -= count;
            value++;
        }
        while (!map.empty() && map.begin()->second == 0) {
            map.erase(map.begin());
        }
    }

    return true;
}

int main() {
    std::vector<int> v{3, 2, 4, 3, 4, 5, 6, 7, 8};
    auto r = isNStraightHand(v, 3);
    dbg(r);
    return 0;
}