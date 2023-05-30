#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (ss >> token) tokens.push_back(token);
    return tokens;
}
int matchValue(int i, int& val);
std::vector<std::string> tks;
// 变量表
std::unordered_map<std::string, int> vt;

int fetchVariable(const std::string& name, int& val) { return vt[name]; }
int matchLet(int i, int& val) {
    printf("Match [let] [%d]\n", i);
    int step = 0;
    while (true) {
        int v;
        int s = matchValue(i + step + 3, v);
        if (s < 0) {
            break;
        }
        printf("[%d] -> %d\n", tks[i + step].c_str(), v);
        step = +s;
    }
    step += matchValue(i + 2 + step, val);
    return step + 2;
}

int matchAdd(int i, int& val) {
    //
    return 1;
}

int matchMult(int i, int& val) {
    //
    return 1;
}

int matchValue(int i, int& val) {
    if (i >= tks.size()) return false;
    if (tks[i] != "(") {
        if (std::all_of(tks[i].begin(), tks[i].end(), [](char c) { return c >= '0' && c <= '9'; })) {
            val = std::strtol(tks[i].c_str(), nullptr, 10);
            return 1;
        } else {
            return fetchVariable(tks[i], val);
        }
    }

    if (tks[i + 1] == "let") return matchLet(i, val);
    if (tks[i + 1] == "add") return matchAdd(i, val);
    return -1;
}

int evaluate(const string& expression) {
    tks = tokenize(expression);
    int val = 0;
    matchValue(0, val);
    return val;
}

int main() {
    dbg(evaluate("( let x 1 y 2 x )"));
    return 0;
};