
#include <stack>
#include <vector>

using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int push_index = 0;
    std::stack<int> st;
    for (int pidx = 0; pidx < popped.size(); pidx++) {
        while (st.empty() || st.top() != popped[pidx]) {
            if (push_index >= pushed.size()) {
                return false;
            }
            st.push(pushed[push_index]);
            push_index++;
            /* code */
        }
        st.pop();
    }
    return true;
}
