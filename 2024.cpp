#include <string>
#include <vector>

#include "dbg.h"

using namespace std;
int maxConsecutiveAnswers(const string &answerKey, int k) {
    std::vector<int> v;
    char last = 'A';
    int ctr = 0;

    for (int i = 0; i < answerKey.size(); i++) {
        char c = answerKey[i];
        if (last != c) {
            if (ctr != 0) {
                v.push_back(ctr);
            }
            ctr = 1;
        } else {
            ctr++;
        }
        last = c;
    }

    if (ctr != 0) v.push_back(ctr);

    dbg(v);
    return 0;
}
int main() {
    maxConsecutiveAnswers("TTFFTTTFFFTTTFTFTF", 12);
    return 0;
}
