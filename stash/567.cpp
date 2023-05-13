#include <string>

#include "dbg.h"

using namespace std;
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }

    std::vector<int> hash(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        hash[s1[i] - 'a']--;
        hash[s2[i] - 'a']++;
    }
    if (std::all_of(hash.begin(), hash.end(), [](int c) { return c == 0; })) {
        return true;
    }
    int cnt = s2.size() - s1.size();
    for (int i = 0; i < cnt; i++) {
        // dbg(s2[i]);
        // dbg(s2[i + s1.size()]);
        hash[s2[i] - 'a']--;
        hash[s2[i + s1.size()] - 'a']++;
        // dbg(hash);
        if (std::all_of(hash.begin(), hash.end(),
                        [](int c) { return c == 0; })) {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[]) {
    dbg(checkInclusion("abc", "xbaci"));
    return 0;
}
