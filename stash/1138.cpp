#include <iostream>
#include <string>
#include <unordered_map>

#include "dbg.h"

using namespace std;
std::string path(char x, char y) {
    if (x == y) return "";
    int cx = (x - 'a') % 5;
    int rx = (x - 'a') / 5;
    int cy = (y - 'a') % 5;
    int ry = (y - 'a') / 5;
    if (x == 'z') {
        std::string res(rx - ry, 'U');
        if (cx != cy) {
            res += std::string(cy - cx, 'R');
        }
        return res;
    }
    if (y == 'z') {
        std::string res;
        if (cx != cy) {
            res += std::string(cx - cy, 'R');
        }
        return res + std::string(ry - rx, 'D');
    }

    char c1 = ry > rx ? 'D' : 'U';
    char c2 = cy > cx ? 'R' : 'L';
    std::string s;
    for (int i = 0; i < abs(ry - rx); i++) {
        s.push_back(c1);
    }
    for (int i = 0; i < abs(cy - cx); i++) {
        s.push_back(c2);
    }
    return s;
}
string alphabetBoardPath(string target) {
    target = "a" + target;
    std::string s;
    for (int i = 1; i < target.size(); i++) {
        s += path(target[i - 1], target[i]) + '!';
    }
    return s;
}
int main() {
    dbg(alphabetBoardPath("code"));
    return 0;
}