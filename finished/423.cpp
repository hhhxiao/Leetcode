#include <iostream>
#include <string>

using namespace std;

//"zero"  x0 = z
//"one"   x1 = o -z - w - u
//"two"   x2 = w
//"three" x3 = h - g
//"four"  x4 = u
//"five"  x5 = f - u
//"six"   x6 = x
//"seven" x7 = s -x
//"eight" x8 = g
//"nine"  x9 = i -f + u - x - g
// e = z +  (o -z - w - u) + (h-g)*2 + (f - u)+ x7*2 + g + x9
// g = x8
// f =  u + x5
// i = f - u + x +g + x9
// h = x3+  g
// o = z + x1 + w + u
// n = (o -z - w - u) + (s-x) + x9 * 2
// s = x + x7
// r = z + h -g + u
// u = x4
// t = w + h
// w = x2
// x = x6
// v = f - u + x7
// z = x0
string originalDigits(const string &s) {
    char hash_table[26];
    for (int i = 0; i < 26; i++) {
        hash_table[i] = 0;
    }
    for (int i = 0; i < s.size(); i++) {
        hash_table[s[i] - 'a']++;
    }
    int counter[10] = {0};
    counter[0] = hash_table['z' - 'a'];
    counter[1] = hash_table['o' - 'a'] - hash_table['z' - 'a'] -
                 hash_table['w' - 'a'] - hash_table['u' - 'a'];
    counter[2] = hash_table['w' - 'a'];
    counter[3] = hash_table['h' - 'a'] - hash_table['g' - 'a'];
    counter[4] = hash_table['u' - 'a'];
    counter[5] = hash_table['f' - 'a'] - hash_table['u' - 'a'];
    counter[6] = hash_table['x' - 'a'];
    counter[7] = hash_table['s' - 'a'] - hash_table['x' - 'a'];
    counter[8] = hash_table['g' - 'a'];
    counter[9] = hash_table['i' - 'a'] - hash_table['f' - 'a'] +
                 hash_table['u' - 'a'] - hash_table['x' - 'a'] -
                 hash_table['g' - 'a'];
    std::string res;
    for (int i = 0; i < 10; i++) {
        if (counter[i] != '0') {
            res += std::string(counter[i], (char)(i + '0'));
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    printf("%s", originalDigits("onetwothreenineninefive").c_str());
    return 0;
}
