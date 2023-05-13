#include <string>
#include <vector>
using namespace std;
int minDeletions(const string& s) {
    std::vector<int> ctr;
    for (int i = 0; i < s.size(); i++) {
        ctr[s[i] - 'a']++;
    }
}