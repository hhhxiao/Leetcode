#include <iostream>
#include <string>

using namespace std;
/*
双引号：字符实体为 &quot; ，对应的字符是 " 。
单引号：字符实体为 &apos; ，对应的字符是 ' 。
与符号：字符实体为 &amp; ，对应对的字符是 & 。
大于号：字符实体为 &gt; ，对应的字符是 > 。
小于号：字符实体为 &lt; ，对应的字符是 < 。
斜线号：字符实体为 &frasl; ，对应的字符是 / 。
*/
string entityParser(string text) {
    text += "#####";
    std::string res;
    int index = 0;
    while (index < text.size()) {
        auto c = text[index];
        if (c == '&') {
            auto forward = text.substr(index + 1, 6);
            if (forward.find("quot;") == 0) {
                res.push_back('\"');
                index += 5;
            } else if (forward.find("apos;") == 0) {
                res.push_back('\'');
                index += 5;
            } else if (forward.find("amp;") == 0) {
                res.push_back('&');
                index += 4;
            } else if (forward.find("gt;") == 0) {
                res.push_back('>');
                index += 3;
            } else if (forward.find("lt;") == 0) {
                res.push_back('<');
                index += 3;
            } else if (forward.find("frasl;") == 0) {
                res.push_back('/');
                index += 6;
            } else {
                res.push_back('&');
            }
        } else {
            res.push_back(c);
        }
        ++index;
    }
    return res.substr(0, res.size() - 5);
}

int main(int argc, char const *argv[]) {
    std::string s = "&&gt;";
    std::cout << entityParser(s);
    return 0;
}
