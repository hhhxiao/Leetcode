#include <string>
using namespace std;

int numSub(string s) {
    s.push_back('0');
    int64_t res = 0;
    // 111
    // 1  + 2  + 3 ==> 6
    // 1  ==> 1
    // 2  1 + 2 ==> 3
    int64_t counter = 0;
    constexpr int M = 1000000007;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            counter++;
        } else if (s[i] == '0') {
            res += (((counter + 1) % M) * (counter % M) / 2) % M;
            res %= M;
            counter = 0;
        }
    }
    return res;
}

int main() {
    numSub("11101011111101");
    return 0;
}