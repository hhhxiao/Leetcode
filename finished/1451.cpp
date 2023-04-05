#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

#include "dbg.h"

using namespace std;

string arrangeWords(string text) {
    std::vector<std::string> tks;
    std::stringstream s(text);
    std::string buffer;
    while (std::getline(s, buffer, ' ')) {
        tks.push_back(buffer);
    }
    dbg(tks);
    std::stable_sort(tks.begin(), tks.end(),
                     [](const std::string &s1, const std::string &s2) { return s1.size() < s2.size(); });
    buffer = tks[0];
    buffer[0] = std::toupper(buffer[0]);
    for (int i = 1; i < tks.size(); i++) {
        tks[i][0] = std::tolower(tks[i][0]);
        buffer += " " + tks[i];
    }
    return buffer;
}

int main() {
    std::string s("This is a text hello world");
    dbg(arrangeWords(s));
    return 0;
}