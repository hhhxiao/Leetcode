#include <iostream>
#include <string>
using namespace std;

string removeDuplicateLetters(const string &s) {
    uint16_t table[26];
    memset(table, 0, sizeof(uint16_t) * 26);
    for (int i = 0; i < s.size(); i++) {
        table[s[i] - 'a']++;
    }

    std::string res;
    res.reserve(26);
    for (int i = 0; i < 26; i++) {
        if (table[i] != 0) {
            res.push_back(static_cast<char>(table[i] + 'a'));
        }
    }
}
