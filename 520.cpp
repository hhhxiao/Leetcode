#include "a.h"
using namespace std;

class Solution {
   public:
    bool detectCapitalUse(const string &word) {
        int la{0};
        int sm{0};
        for (auto c : word) {
            if (c >= 'A' && c <= 'Z') la++;
        }

        return word.empty() || la == word.size() || la == 0 ||
               (la == 1 && (word[0] >= 'A' && word[0] <= 'Z'));
    }
};
