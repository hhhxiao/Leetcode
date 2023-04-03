#include <iostream>
using namespace std;
#include "dbg.h"
int minSwaps(const string& s) {
    int odd_1 = 0;
    int even_1 = 0;
    int odd_0 = 0;
    int even_0 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {  // 偶数位
            if (s[i] == '0') {
                even_0++;
            } else {
                even_1++;
            }
        } else {
            if (s[i] == '0') {
                odd_0++;
            } else {
                odd_1++;
            }
        }
    }

    int zero = odd_0 + even_0;
    int one = odd_1 + even_1;

    dbg(odd_0, odd_1, even_0, even_1);

    if (abs(zero - one) > 1) {
        return -1;
    }

    if (zero == one) {
        // 111000
        return std::min(odd_0, odd_1);
    } else if (zero > one) {
        // 0只能偶数位,1只能奇数位
        return odd_0;
    } else if (zero < one) {
        // 1只能偶数位,0只能奇数位
        return odd_1;
    }
    return -1;
}

int main() {
    dbg(minSwaps("111000"));
    return 0;
}