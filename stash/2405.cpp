#include <bitset>
#include <string>
#include <type_traits>

#include "a.h"

using namespace std;

int partitionString(string s) {
    std::bitset<32> m;
    int n = 0;
    for (int i = 0; i < s.size(); i++) {
        auto x = s[i] - 'a';
        if (m.test(x)) {
            m.reset();
            n++;
        }
        m.set(x);
    }

    if (m.any()) n++;
    return n;
}
int main() {
    std::string s = "ssssss";

    dbg(partitionString(s));

    return 0;
}
