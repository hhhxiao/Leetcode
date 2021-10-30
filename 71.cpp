#include <iostream>
#include <stack>
#include <string>

#include "dbg.h"

using namespace std;

string simplifyPath(string path) {
    path.push_back('/');
    std::stack<std::string> s;
    std::string buffer;
    for (int i = 0; i < path.size(); i++) {
        char c = path[i];
        if (c == '/') {
            if (!buffer.empty()) {
                dbg(buffer);
                if (buffer == "..") {
                    if (!s.empty()) s.pop();
                } else if (buffer != ".") {
                    s.push(buffer);
                }
                buffer.clear();
            }
        } else {
            buffer.push_back(c);
        }
    }
    std::string res;
    while (!s.empty()) {
        res = "/" + s.top() + res;
        s.pop();
    }
    if (res.empty()) res = "/";
    return res;
}

int main(int argc, char const *argv[]) {
    dbg(simplifyPath("/../"));
    return 0;
}
