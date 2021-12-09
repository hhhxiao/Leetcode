#include <iostream>
#include <map>
#include <vector>

#include "dbg.h"

using namespace std;
bool isPossible(vector<int>& nums) {
    dbg(nums);
    std::map<int, int> table;
    for (int i = 0; i < nums.size(); i++) {
        table[nums[i]]++;
    }

    bool found = true;
    while (table.size() >= 3) {
        dbg(table);
        auto iter = table.begin();
        int count = 0;
        auto val = iter->first - 1;
        for (; iter != table.end();) {
            dbg(iter->first);
            if (iter->first == val + 1) {
                val = iter->first;
                count++;
                iter->second--;
                if (iter->second == 0) {
                    table.erase(iter++);  // or "it = m.erase(it)" since C++11
                } else {
                    iter++;
                }
            } else {
                break;
            }
        }
        dbg(count);
        if (count < 3) {
            return false;
        }
    }

    return table.empty();
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {1, 2, 3, 3, 4, 5};
    dbg(isPossible(v));
    return 0;
}
