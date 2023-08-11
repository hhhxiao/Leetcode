#include <stdio.h>

#include <algorithm>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

vector<string> printVertically(string s) {
    std::stringstream ss(s);
    std::string x;
    std::vector<std::string> vec;
    int max_len = 0;
    while (ss >> x) {
        vec.push_back(x);
        max_len = std::max(max_len, static_cast<int>(x.size()));
    }

    // dbg(vec);
    // dbg(max_len);
    std::vector<string> res;

    for (int i = 0; i < max_len; i++) {
        std::string buf;

        for (int j = 0; j < vec.size(); j++) {
            auto c = vec[j].size() > i ? vec[j][i] : ' ';
            buf += c;
        }
        while (buf.size() > 0 && buf.back() == ' ') buf.pop_back();

        res.push_back(buf);
    }

    return res;
}

int main() {
    std::string s = "HOW ARE YOU";
    dbg(printVertically(s));
    return 0;
}
