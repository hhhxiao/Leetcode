#include <algorithm>
#include <iostream>
#include <string>

#include "dbg.h"

bool isInteger(const std::string& s) {
    if (s.empty()) return false;
    int index = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) return false;
        index++;
    }
    dbg(index);
    return s.size() >= 1 && std::all_of(s.begin() + index, s.end(), [](char c) {
               return c >= '0' && c <= '9';
           });
}

bool isFloat(const std::string& s, int index_point) {
    if (s.size() <= 1) {
        return false;
    }
    int index = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 2) return false;
        index++;
    }
    return std::all_of(s.begin() + index, s.begin() + index_point - 1,
                       [](char c) { return c >= '0' && c <= '9'; }) &&
           std::all_of(s.begin() + index_point + 1, s.end(),
                       [](char c) { return c >= '0' && c <= '9'; });

    return true;
}

using namespace std;
bool isNumber(std::string trimed) {
    size_t endpos = trimed.find_last_not_of(" \t");
    size_t startpos = trimed.find_first_not_of(" \t");
    if (std::string::npos != endpos) {
        trimed = trimed.substr(0, endpos + 1);
        trimed = trimed.substr(startpos);
    } else {
        trimed.erase(std::remove(std::begin(trimed), std::end(trimed), ' '),
                     std::end(trimed));
    }

    dbg(trimed);
    bool existE = false;
    int idx_E = -1;
    bool existPoint = false;
    int idx_Point = -1;
    bool existSpace = false;

    for (int i = 0; i < trimed.size(); i++) {
        char c = trimed[i];
        if (c == 'e' || c == 'E') {
            if (existE) return false;
            existE = true;
            idx_E = i;
        }
        if (c == '.') {
            if (existPoint) return false;
            existPoint = true;
            idx_Point = i;
        }
        if (c == ' ') return false;
    }
    if (existE) {
        if (idx_Point > idx_E) {
            return false;
        }

        auto left = trimed.substr(0, idx_E);
        auto right = trimed.substr(idx_E + 1);
        bool c1 = existPoint ? isFloat(left, idx_Point) : isInteger(left);
        return c1 && isInteger(right);
    } else {
        // dbg("No E\n");
        // dbg(existPoint);
        // dbg(trimed);
        return existPoint ? isFloat(trimed, idx_Point) : isInteger(trimed);
    }
}

int main(int argc, char const* argv[]) {
    dbg(isNumber(" "));
    return 0;
}
