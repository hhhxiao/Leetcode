#include <iostream>
#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

bool valid(std::string &s) {
    if (s.size() == 1) {
        return true;
    } else if (s.size() == 2) {
        return s[0] != '0';
    }
    s <= "255";
}
void search_addr(std::string &str, int begin_index, int last,
                 std::string &buffer, std::vector<std::string> &res) {
    if (last == 1) {
        auto part = str.substr(begin_index, str.length() - begin_index);
        if (valid(part)) {
            auto r = buffer + "." + part;
            res.push_back(r);
        }
        return;
    }
    int last_len = str.length() - begin_index;
    int min_len = (last - 1);
    int max_len = (last - 1) * 3;
    for (int l = 1; l <= 3; l++) {
        int c_len = last_len - l;
        if (c_len >= min_len && c_len <= max_len) {
            auto new_part = str.substr(begin_index, l);

            if (valid(new_part)) {
                if (buffer.empty()) {
                    search_addr(str, begin_index + l, last - 1, new_part, res);
                } else {
                    auto buff = buffer + "." + str.substr(begin_index, l);
                    search_addr(str, begin_index + l, last - 1, buff, res);
                }
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    std::string buffer;
    std::vector<std::string> res;
    search_addr(s, 0, 4, buffer, res);
    return res;
}

int main(int argc, char const *argv[]) {
    std::string s = "12345678";
    dbg(restoreIpAddresses(s));
    return 0;
}
