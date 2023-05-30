#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

int minSwaps(string s) {
    int res = 0;
    vector<char> stack;
    int cur = 0;
    int find_index = s.size() - 1;
    while (cur < s.size()) {
        if (s[cur] == '[') {
            stack.push_back('[');

        } else {
            // cur = ]
            if (!stack.empty() && stack.back() == '[') {
                stack.pop_back();
            } else {
                // find next ]
                // find_index = max(find_index, cur + 1);
                while (find_index >= 0 && s[find_index] != '[') find_index--;
                std::swap(s[cur], s[find_index]);
                stack.push_back('[');
                find_index--;
                res++;
            }
        }
        ++cur;
    }
    return res;
}
int main() {
    dbg(minSwaps("[[[[]][]]]"));
    return 0;
}
