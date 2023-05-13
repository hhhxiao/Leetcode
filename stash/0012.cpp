#include <iostream>
#include <string>

#include "dbg.h"

using namespace std;

std::string Get(int num, int level) {
    static const char *level_map_1 = "IXCM";
    static const char *level_map_5 = "VLD";

    if (num <= 3) {
        return std::string(num, level_map_1[level]);
    } else if (num == 4) {
        std::string res(2, ' ');
        res[0] = level_map_1[level];
        res[1] = level_map_5[level];
        return res;
    } else if (num <= 8) {
        const int x = num - 5;
        std::string res(1, level_map_5[level]);
        for (int i = 0; i < x; i++) res.push_back(level_map_1[level]);
        return res;
    } else if (num == 9) {
        std::string res(2, level_map_1[level]);
        res[1] = level_map_1[level + 1];
        return res;
    }
    return "";
}
string intToRoman(int num) {
    int level = 0;
    std::string r;
    while (num > 0) {
        r = Get(num % 10, level) + r;
        level++;
        num /= 10;
    }
    return r;
}
int main(int argc, char const *argv[]) {
    dbg(intToRoman(1234));
    return 0;
}
