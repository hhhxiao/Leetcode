#include <cmath>
#include <string>

#include "dbg.h"

using namespace std;

string getHint(string secret, string guess) {
    const auto sz = secret.length();
    int A = 0, B = 0;
    char map[10];
    for (int i = 0; i < 10; i++) map[i] = 0;
    for (int i = 0; i < sz; i++) {
        if (secret[i] == guess[i]) {
            A++;
        } else {
            map[secret[i - '0']]++;
            map[guess[i - '0']]--;
        }
    }
    for (int i = 0; i < 10; i++) {
        B += abs(map[i]);
    }

    return std::to_string(A) + "A" + std::to_string(B) + "B";
}
int main(int argc, char const *argv[]) { 
    auto s1 = "10101";
    DBG();
    return 0;
    
     }
