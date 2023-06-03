#include "a.h"
#include "dbg.h"
using namespace std;

void solve(int m, int n, int &last, int &N) {
    if (m % n == 0) {  // 5 10 15 20
        last = n;
        N = m / n - 1;
        return;
    }

    if (m < n) {  // 0,1,2,3,4
        last = m;
        N = 0;
        return;
    }

    int part = m / n + 1;
    last = m / part;
    N = part - 1;
}

long long minimumReplacement(vector<int> &nums) {
    long long res = 0;
    if (nums.size() == 1) return 0;
    int last = nums.back();
    for (int i = nums.size() - 2; i >= 0; i--) {
        printf("cur = %d last =%d\n", nums[i], last);
        int n = last;
        int ctr = 0;
        solve(nums[i], n, last, ctr);
        res += ctr;
    }
    return res;
}

int main() {
    vector<int> x{12, 9, 7, 6, 17, 19, 21};
    dbg(minimumReplacement(x));

    return 0;
}