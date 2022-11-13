#include <cstdint>
#include <cstdio>
#include <string>

using namespace std;

bool isNumber(char c) { return c >= '0' && c <= '9'; }

int myAtoi(string s) {
    int index = 0;
    while (s[index] == ' ') {
        ++index;
    }
    bool positive = true;
    if (s[index] == '-') {
        positive = false;
        ++index;
    }
    int64_t res = 0;
    while (isNumber(s[index])) {
        auto number = static_cast<int>(s[index] - '0');
        res = (res * 10) + number;
        if (res > INT32_MAX) {
            break;
        }
        ++index;
    }

    if (!positive) {
        res *= -1;
    }

    if (res > INT32_MAX) res = INT32_MAX;
    if (res < INT32_MIN) res = INT32_MIN;
    return static_cast<int>(res);
}

int main(int argc, char const *argv[]) {
    myAtoi("-123");
    return 0;
}
