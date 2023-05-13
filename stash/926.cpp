#include <iostream>
#include <string>
using namespace std;
int minFlipsMonoIncr(const string& s) {
    int zero_cnt = 0;
    int one_cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') zero_cnt++;
        if (s[i] == '1') one_cnt++;
    }

    int l0 = 0;
    int l1 = 0;

    int cost = min(zero_cnt, one_cnt);
    printf("Cost  = %d\n", cost);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') l0++;
        if (s[i] == '1') l1++;
        int c = l1 + (zero_cnt - l0);
        printf("c = %d\n", c);
        if (cost > c) cost = c;
    }
    return cost;
}

int main() { std::cout << minFlipsMonoIncr("11000101"); }
