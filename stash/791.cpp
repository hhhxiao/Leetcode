#include <algorithm>

#include "a.h"

using namespace std;
string customSortString(string order, string s) {
    int arr[26]{0};
    for (int i = 0; i < order.size(); i++) {
        arr[order[i] - 'a'] = i;
    }

    std::sort(s.begin(), s.end(), [arr](char a, char b) { return arr[a - 'a'] < arr[b - 'a']; });

    return s;
}

int main() { return 0; }