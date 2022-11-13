#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
int longestPalindrome(vector<string>& words) {
    int size = 0;

    std::unordered_map<std::string, int> ctr;
    for (int i = 0; i < words.size(); i++) {
        ctr[words[i]]++;
    }
    int contan_single = 0;
    while (!ctr.empty()) {
        auto ele = ctr.begin();
        auto token = ele->first;
        if (token[0] == token[1]) {
            size += ele->second / 2 * 4;
            if (ele->second % 2 == 1) {
                contan_single = 2;
            }
        } else {
            std::string rev(2, token[1]);
            rev[1] = token[0];
            auto res = ctr.find(rev);
            if (res != ctr.end()) {
                size += min(ele->second, res->second) * 4;
                // printf("[%s] x %d\n", token.c_str(),

                //        min(ele->second, res->second));

                ctr.erase(res->first);
            }
        }
        ctr.erase(token);
    }

    return size + contan_single;
}

int main() {
    std::vector<std::string> words = {"tc", "ct", "tr", "tc",
                                      "rt", "rr", "mr", "ct"};

    longestPalindrome(words);
    return 0;
}
