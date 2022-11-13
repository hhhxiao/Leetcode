#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool isValid(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int bit_index(char c) {
    if (c == 'a') return 0;
    if (c == 'e') return 1;
    if (c == 'i') return 2;
    if (c == 'o') return 3;
    if (c == 'u') return 4;
    return -1;
}

int findTheLongestSubstring(string s) {
    std::unordered_map<std::bitset<5>, int> map;
    std::bitset<5> sum;
    map[0] = -1;
    int max = -1;
    for (int i = 0; i < s.size(); i++) {
        if (isValid(s[i])) sum[bit_index(s[i])].flip();
        auto res = map.find(sum);
        if (res != map.end()) {
            int dis = i - res->second;
            if (max < dis) {
                max = dis;
            }
        } else {
            map[sum] = i;
        }
    }
    return 0;
}

int main() {
    std::string s = "eleetminicoworoep";
    findTheLongestSubstring(s);
}
