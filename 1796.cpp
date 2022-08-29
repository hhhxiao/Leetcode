#include <iostream>
using namespace std;
int secondHighest(const std::string& s) {
    int arr[10] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= '9' && s[i] >= '0') {
            arr[s[i] - '0']++;
        }
    }

    int cnt = 0;

    for (int i = 9; i >= 0; i--) {
        if (arr[i] > 0) {
            if (cnt == 1) return i;
            cnt++;
        }
    }
    return -1;
}