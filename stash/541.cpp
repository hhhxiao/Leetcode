#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
string reverseStr(string s, int k) {
    auto index = 0u;

    bool flag = true;
    std::string res;
    while (index < s.size()) {
        int end = std::min(static_cast<size_t>(index + k), s.size());
        // printf("[%d~%d) => %d\n", index, end, flag);
        if (flag) {
            std::reverse(s.begin() + index, s.begin() + end);
        }
        flag = !flag;
        index = end;
    }

    return s;
}

int main(int argc, const char *argv[]) {
    std::cout << reverseStr("12345678abced", 2);
    return 0;
}
