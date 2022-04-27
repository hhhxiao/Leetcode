#include <string>
#include <iostream>
using namespace std;
bool isSubsequence(string s, string t) {
    int to_find = 0;
    int index = 0;
    while (index < t.size()) {  
        if(to_find >= s.size())return true;
        while (t[index] != s[to_find]) {
            ++index;
            if(index >= t.size()){
                return false;
            }
        }
        ++to_find;
    }
    return true;
}

int main(){
    isSubsequence("abc","dcaaxbc");
    return 0;
}

