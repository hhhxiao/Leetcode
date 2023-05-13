#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_subsquence(const string& s, const string& r) {
    // aabcbabsdasd  aabc
    int idx = 0;
    int rdx = 0;

    while (rdx < r.size()) {
        printf("Finding [%c]\n", r[rdx]);
        while (idx < s.size() && s[idx] != r[rdx]) idx++;
        if (idx >= s.size()) return false;
        ++idx;
        ++rdx;
    }
    return true;
}

string findLongestWord(string s, vector<string>& dictionary) {
    int idx = -1;
    int len = -1;
    for (int i = 0; i < dictionary.size(); i++) {
        if (is_subsquence(s, dictionary[i])) {
            int cur_len = dictionary[i].size();
            if (cur_len > len) {
                idx = i;
                len = cur_len;
            } else if (cur_len == len) {
                if (dictionary[i] < dictionary[idx]) {
                    idx = i;
                    len = cur_len;
                }
            }
        }
    }

    return dictionary[idx];
}
int main(int argc, char const* argv[]) {
    std::cout << is_subsquence("apple", "zxn");
    return 0;
}