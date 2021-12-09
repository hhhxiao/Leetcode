#include <iostream>
#include <string>
using namespace std;

int minFlipsMonoIncr(const string& s) {
    int ctr_0 = 0;
    int ctr_1 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1')
            ctr_1++;
        else if (s[i] == '0')
            ctr_1++;
    }

    int buff_0 = 0;
    int buff_1 = 0;
    int min = INT32_MAX;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            buff_1++;
        } else if (s[i] == '0') {
            buff_0++;
        }

        int diff = buff_1 + (ctr_0 - buff_0);
        if (min > diff) min = diff;
    }

    return min;
}

int main(int argc, char const* argv[]) { return 0; }
