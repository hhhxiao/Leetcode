#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
int compress(std::string& chars) {
    auto last = char{0};
    chars.push_back(0);
    int len = 0;
    int ctr = 0;
    for (int i = 0; i < chars.size(); i++) {
        auto c = chars[i];
        if (c == last) {
            ctr++;
        } else {
            if (ctr > 0) {
                chars[len++] = last;
                if (ctr >= 2 && ctr <= 9) {
                    chars[len++] = ctr + '0';
                } else if (ctr >= 10 && ctr <= 99) {
                    chars[len++] = (ctr / 10) + '0';
                    chars[len++] = (ctr % 10) + '0';
                } else if (ctr >= 100 && ctr <= 999) {
                    chars[len++] = (ctr / 100) + '0';
                    chars[len++] = ((ctr % 100) / 10) + '0';
                    chars[len++] = ((ctr % 100) % 10) + '0';
                } else if (ctr >= 1000) {
                    chars[len++] = (ctr / 1000) + '0';
                    chars[len++] = ((ctr % 1000) / 100) + '0';
                    chars[len++] = ((ctr % 100) / 10) + '0';
                    chars[len++] = (ctr % 10) + '0';
                }
            }
            ctr = 1;
            last = c;
        }
    }
    chars.resize(len);
    return 0;
}

int main() {
    std::string s = "aabbccxxxxxxxxxx";
    dbg(compress(s));
    printf("%s", s.c_str());
    return 0;
}
