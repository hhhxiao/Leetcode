#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

#include "dbg.h"

using namespace std;
string reverseParentheses(string s) {
    std::stack<char> st;
    for (size_t i = 0; i < s.size(); i++) {
        printf("Meets %c\n", s[i]);
        char c = s[i];
        if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            std::string buffer;
            while (!st.empty() && st.top() != '(') {
                buffer.push_back(st.top());
                st.pop();
            }
            dbg(buffer);
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            for (int j = 0; j < buffer.size(); j++) {
                st.push(buffer[j]);
            }
        } else {
            st.push(c);
        }
    }
    std::string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }

    return std::string(res.rbegin(), res.rend());
}

int main() {
    std::cout << "res = \n" << reverseParentheses("(u(love)i)");
    return 0;
}