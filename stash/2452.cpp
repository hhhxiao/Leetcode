#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    std::vector<std::string> res;
    std::copy_if(queries.begin(), queries.end(), std::back_inserter(res), [&](const std::string& s) {
        for (auto& d : dictionary) {
            if (d.size() != s.size()) {
                continue;
            }
            int sz = 0;
            for (int i = 0; i < s.size(); i++) {
                if (d[i] != s[i]) sz++;
            }
            if (sz <= 2) return true;
        }
        return false;
    });
    return res;
}
