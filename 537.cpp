#include <iostream>
#include <string>

using namespace std;

void parse(const std::string &s, int &r, int &i) {
    int pos = s.find('+');
    auto real = s.substr(0, pos);
    auto img = s.substr(pos + 1, s.size() - pos - 2);
    r = strtol(real.c_str(), nullptr, 10);
    i = strtol(img.c_str(), nullptr, 10);
}

string complexNumberMultiply(string num1, string num2) {
    // a+bi  c+di
    int r1, i1, r2, i2;
    parse(num1, r1, i1);
    parse(num2, r2, i2);
    return std::to_string(r1 * r2 - i1 * i2) + "+" +
           std::to_string(r1 * i2 + r2 * i1) + "i";
}

int main() {
    int a = 0, b = 0;
    parse("512+-1234i", a, b);
    return 0;
}