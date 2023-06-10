#include <algorithm>
#include <vector>

#include "a.h"

using namespace std;

void search(int start, int n, int k, vector<int>& buf, vector<vector<int>>& res) {
    if (start > n || buf.size() == k) {
        if (buf.size() == k) {
            res.push_back(buf);
        }
        return;
    }

    for (int i = start; i <= n; i++) {
        buf.push_back(i);
        search(i + 1, n, k, buf, res);
        buf.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    std::vector<int> v;
    vector<vector<int>> res;
    search(1, n, k, v, res);
    return res;
}

int main() {
    dbg(combine(4, 2));
    return 0;
}
