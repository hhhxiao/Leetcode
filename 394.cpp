#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_number(char c) { return c >= '0' && c <= '9'; }
// 4[aaa5[aqw]]
string decodeString(const string &s) {
    std::stack<std::string> st;
    std::string stack_buffer;
    for (size_t i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '[' || c == ']') {
            if (!stack_buffer.empty()) {
                st.push(stack_buffer);
                if (c == '[') {
                    printf("Push number: %s\n", stack_buffer.c_str());
                } else {
                    printf("Push string: %s\n", stack_buffer.c_str());
                }
                stack_buffer.clear();
            }

            if (c == ']') {
                auto top = st.top();
                std::string str;

                while (!is_number(top[0])) {
                    st.pop();
                    str = top + str;
                    top = st.top();
                }

                auto ctr = strtol(st.top().c_str(), nullptr, 10);
                st.pop();
                std::string temp;
                printf("Ctr = %d, str = %s\n", ctr, str.c_str());
                temp.reserve(str.size() * ctr);
                for (int i = 0; i < ctr; i++) {
                    temp += str;
                }
                st.push(temp);
            }
        } else {
            // number
            if (is_number(c)) {
                if (!stack_buffer.empty() && !is_number(stack_buffer[0])) {
                    st.push(stack_buffer);
                    printf("Push string: %s\n", stack_buffer.c_str());
                    stack_buffer.clear();
                }
                stack_buffer.push_back(c);
            } else {
                stack_buffer.push_back(c);
            }
        }
    }
    std::string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    return res + stack_buffer;
}

int main(int argc, char const *argv[]) {
    printf("%s", decodeString("3[abc2[x2[y]]]tt").c_str());
    return 0;
}
