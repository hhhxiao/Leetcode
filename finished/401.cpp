#include <bitset>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search(std::bitset<10> &s, int min, int remain,
            std::vector<std::string> &res) {
    if (remain == 0) {
        auto v = s.to_ulong();
        int hour = v >> 6;
        int min = v & 0b0000111111;
        if (hour >= 0 && hour <= 11 && min >= 0 && min <= 59) {
            char buff[16];
            memset(buff, 0, 16 * sizeof(char));
            sprintf(buff, "%d::%02d", hour, min);
            res.emplace_back(buff);
        }
        return;
    }
    if (min >= s.size()) return;
    s.set(min);
    search(s, min + 1, remain - 1, res);
    s.reset(min);
    search(s, min + 1, remain, res);
}
vector<string> readBinaryWatch(int turnedOn) {
    std::vector<std::string> res;
    std::bitset<10> s;
    search(s, 0, turnedOn, res);
    return res;
}

int main() {
    auto r = readBinaryWatch(1);
    for (auto &t : r) {
        printf("%s\n", t.c_str());
    }
    return 0;
}