#include <string>
using namespace std;
#include <stack>
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'b') {
            st.push(s[i]);
        } else if (s[i] == 'c') {
            if (st.size() <= 1) {
                return false;
            }
            auto c1 = st.top();
            st.pop();
            auto c2 = st.top();
            st.pop();
            if (c1 != 'b' || c2 != 'a') {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    std::string s = "aabcbababccabccabc";

    printf("%d", isValid(s));
}