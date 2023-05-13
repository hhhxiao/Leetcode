#include <string>
using namespace std;
class Solution {
   public:
    int countHomogenous(string s) {
        const int mod = 1000000007;
        int64_t res = 0;
        int64_t counter = 0;
        char buffer = '?';
        for (int i = 0; i < s.size(); i++) {
            if (counter == 0) {
                buffer = s[i];
                counter++;
            } else if (s[i] == buffer) {
                counter++;
            } else {
                res += counter * (counter + 1) / 2;
                res %= mod;
                counter = 1;
                buffer = s[i];
            }
        }
        res += counter * (counter + 1) / 2;
        res %= mod;
        return res;
    }
};
