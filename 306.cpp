#include <iostream>
#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

int search(const std::string& s, int pos, std::vector<int64_t>& queue) {
    if (pos >= s.size()) {
        dbg(queue);
        return queue.size() >= 3;
    }

    const auto MAX_LEN = s.size() / 2 + 1;  // 保守一点
    int cur = 0;
    for (int i = 0; i < MAX_LEN && i + pos < s.size(); i++) {
        cur *= 10;
        cur += (s[i + pos] - '0');
        // 不允许有前导0
        if (!(i > 0 && s[pos] == '0')) {
            if (queue.size() < 2 || queue[queue.size() - 2] + queue[queue.size() - 1] == cur) {
                printf("Search\n");
                queue.push_back(cur);
                if (search(s, i + pos + 1, queue)) {
                    return true;
                }
                queue.pop_back();
            }
        }
    }

    return false;
}

bool isAdditiveNumber(string num) {
    std::vector<int64_t> q;
    return search(num, 0, q);
    return true;
}

int main() {
    std::string s = "11011";
    dbg(isAdditiveNumber(s));
    return 0;
}