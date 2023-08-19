#include <stdio.h>

#include <string>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

std::string combine(vector<string>& w, int b, int e, int sw, bool last) {
    if (e - b == 1) return sw > 0 ? w[b] + std::string(sw, ' ') : w[b];

    int space_wdith = sw / (e - b - 1);
    std::string res;

    int x = 0;
    for (int i = b; i < e - 1; i++) {
        if (last) {
            res += w[i] + " ";
        } else {
            res +=
                w[i] + std::string(
                           x < sw - space_wdith * (e - b - 1) ? space_wdith + 1 : space_wdith, ' ');
        }
        x++;
    }

    res += w[e - 1];
    if (last) {
        int least = sw - (e - b - 1);
        if (least > 0) res += std::string(least, ' ');
    }

    return res;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int index = 0;

    int len{0};
    int n{0};
    int begin = 0;

    std::vector<string> res;

    while (index <= words.size()) {
        if (index >= words.size() || (len + words[index].size() + n > maxWidth)) {
            // res.emplace_back(begin, index);
            res.push_back(combine(words, begin, index, maxWidth - len, index >= words.size()));
            n = 1;
            len = index < words.size() ? words[index].size() : 0;

            begin = index;

            // print
        } else {
            len += words[index].size();
            n++;
        }
        index++;
    }
    return res;
}

int main() {
    std::vector<std::string> v{"a"};
    auto res = fullJustify(v, 1);
    for (auto i : res) {
        printf("|%s|\n", i.c_str());
    }

    return 0;
}