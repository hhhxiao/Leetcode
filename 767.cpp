#ifndef XX

#define XX
#include <cstdio>

int main() { printf("\n"); }

#endif

// #include <cstdio>
// #include <cstring>
// #include <string>
// #include <unordered_map>

// using namespace std;
// string reorganizeString(const string &s) {
//     int t[26];
//     memset(t, 0, 26 * sizeof(int));
//     for (int i = 0; i < s.size(); i++) {
//         t[s[i] - 'a']++;
//     }

//     std::string res;
//     int begin = 0;
//     int end = 25;
//     while (true) {
//         while (begin < 26 && t[begin] == 0) begin++;
//         while (end >= 0 && t[end] == 0) end--;
//         if (begin >= end) {
//             break;
//         }
//         printf("begin  = %d(%d),end = %d(%d)\n", begin, t[begin], end,
//         t[end]); int m = min(t[begin], t[end]); for (int i = 0; i < m; i++) {
//             res.push_back(begin + 'a');
//             res.push_back(end + 'a');
//         }
//         t[begin] -= m;
//         t[end] -= m;
//     }
//     printf("begin = %d,end = %d", begin, end);
//     printf("res = %s", res.c_str());
//     return res;
// }
// int main() {
//     reorganizeString("abbcc");
//     return 0;
// }