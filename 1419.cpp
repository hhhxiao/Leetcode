#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int minNumberOfFrogs(const string &croakOfFrogs) {
    std::unordered_map<char, int> map;
    for (int i = 0; i < croakOfFrogs.size(); i++) {
        auto c = croakOfFrogs[i];
        if (c == 'c') {
            map['r']++;
        } else {
            auto iter = map.find(c);
            if (iter == map.end() || iter->second == 0) {
                return -1;
            }
            if (c == 'r') {
                map['r']--;
                map['o']++;

            } else if (c == 'o') {
                map['o']--;
                map['a']++;
            } else if (c == 'a') {
                map['a']--;
                map['k']++;
            } else if (c == 'k') {
                map['k']--;
                map['f']++;
            }
        }
    }
    int num = 0;
    for (auto kv : map) {
        printf("%c => %d\n", kv.first, kv.second);
        if (kv.first == 'f') {
            num = kv.second;
        } else {
            if (kv.second != 0) {
                return -1;
            }
        }
    }
    return num;
}

int main(int argc, char const *argv[]) {
    std::cout << minNumberOfFrogs("ccrororcaakokak");
    return 0;
}
