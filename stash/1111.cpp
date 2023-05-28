#include <string>
#include <vector>

#include "dbg.h"

using namespace std;

vector<int> maxDepthAfterSplit(const string &seq) {
    std::vector<int> v(seq.size(), 0);
    int depth = 1;
    int md = 1;
    for (int i = 0; i < seq.size(); i++) {
        auto c = seq[i];
        if (c == '(') {
            v[i] = depth;
            depth++;
            if (md < depth) md = depth;
        } else {
            depth--;
            v[i] = depth;
        }
    }

    // dbg(v);
    // std::string s0, s1;

    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] > md / 2 ? 1 : 0;
        // if (v[i] == 0) {
        //     s0.push_back(seq[i]);
        // } else {
        //     s1.push_back(seq[i]);
        // }
    }
    // dbg(v);
    // dbg(s0);
    // dbg(s1);
    return v;
}
int main() {
    dbg(maxDepthAfterSplit("(((())))(((())))(())"));
    return 0;
}
