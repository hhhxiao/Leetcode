#include <iostream>
#include <string>

#include "dbg.h"

int cal(int a, int b, char c) {
    printf("cal %d %c %d\n", a, c, b);
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;

    return 0;
}

bool comp(char c, char a) {
    if (a == '#') return false;
    if (c == '*' || c == '/') return true;
    if ((c == '+' || c == '-') && (a == '+' || a == '-')) return true;
    return false;
}

int calculate(const std::string& str) {
    std::string s;
    for (auto c : str) {
        if (c != ' ') s.push_back(c);
    }
    s.push_back('#');

    std::vector<int> ns, ss;  //数字栈和符号栈
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= '0' && c <= '9') {
            num *= 10;
            num += (c - '0');
        } else {
            ns.push_back(num);
            num = 0;
            if (!ss.empty()) {
                printf("Compare %c to %c\n", c, ss.back());
                if (comp(ss.back(), c)) {
                    //找到栈顶数据进行计算
                    auto n2 = ns.back();
                    ns.pop_back();
                    auto n1 = ns.back();
                    ns.pop_back();
                    ns.push_back(cal(n1, n2, ss.back()));
                    ss.pop_back();
                }
            }
            if (c != '#') ss.push_back(c);
        }
    }
    // dbg(ns);
    // dbg(ss);
    if (ss.empty()) return ns[0];
    int index = 0;
    int value = ns[0];
    int ni = 1;
    while (index < ss.size()) {
        value = cal(value, ns[ni], ss[index]);
        ++ni;
        ++index;
    }
    dbg(value);
    return value;
}

int main() {
    calculate("20-2*2*2-2-1");
    return 0;
}