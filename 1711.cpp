#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "dbg.h"

using namespace std;

int countPairs(vector<int>& deliciousness) {
    if (deliciousness.size() < 2) return 0;
    int result = 0;
    const int ARR[] = {0,      1,      2,      4,       8,      16,
                       32,     64,     128,    256,     512,    1024,
                       2048,   4096,   8192,   16384,   32768,  65536,
                       131072, 262144, 524288, 1048576, 2097152

    };

    std::unordered_map<int, uint16_t> ctr;
    int min = INT32_MAX, max = INT32_MIN;
    for (auto& i : deliciousness) {
        if (i > max) {
            max = i;
        }
        if (i < min) {
            min = i;
        }
        ctr[i]++;
    }

    min <<= 1;
    max <<= 1;
    int min_idx = 0;
    int max_idx = 22;
    while (ARR[min_idx] < min) {
        ++min_idx;
    }
    while (ARR[max_idx] > max) {
        --max_idx;
    }
    dbg(ctr);
    dbg(ARR[min_idx]);
    dbg(ARR[max_idx]);

    std::vector<std::pair<int, int>> pairs;

    while (!ctr.empty()) {
        auto kv = ctr.begin();
        for (int idx = min_idx; idx <= max_idx; idx++) {
            auto iter = ctr.find(ARR[idx] - kv->first);
            if (iter != ctr.end()) {
                int c = 0;
                if (iter->first == kv->first) {
                    c = iter->second * (iter->second - 1) / 2;
                } else {
                    c = iter->second * kv->second;
                }
                printf("%d + %d = %d ==> %d\n", kv->first, iter->first,
                       ARR[idx], c);
                result += c;
                result %= 1000000007;
            }
        }
        ctr.erase(kv);
    }

    return result;
}
int main(int argc, char const* argv[]) {
    std::vector<int> r = {0, 0, 0, 0, 0};
    countPairs(r);
    return 0;
}
