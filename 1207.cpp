#include <vector>

#include "dbg.h"

using namespace std;
bool uniqueOccurrences(vector<int>& arr) {
    std::vector<int> table(2001, 0);
    for (int i = 0; i < arr.size(); i++) {
        table[arr[i] + 1000]++;
    }
    std::vector<int> ctr(1000, 0);
    for (int i = 0; i < table.size(); i++) {
        if (table[i] != 0) {
            printf("[%d]: %d times\n", i - 1000, table[i]);
            if (ctr[table[i]] == 0) {
                ctr[table[i]] = 1;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {1, 1, 2, 3, 5, 7, 1, 2, 3};
    uniqueOccurrences(v);
    return 0;
}
