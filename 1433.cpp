#include <algorithm>
#include <string>

using namespace std;
bool checkIfCanBreak(string s1, string s2) {
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
    int sum_1 = 0;
    int sum_2 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] >= s2[i]) {
            sum_1++;
        }
        if (s1[i] <= s2[i]) {
            sum_2++;
        }
    }
    return sum_1 == s1.size() || sum_2 == s1.size();
}

int main() { return 0; }