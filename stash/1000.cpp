#include <vector>
using namespace std;

/*
 * 典型dp题
 * [a1,a2,...an]
 * 合并后变成 [a1,...ai,M = (ai+1,..ai+k-1),...am]
 *
 *
 * S[n]
 * S[n - (k-1)]
 * S[n - (k-1) * 2]
 * S[n - (k-1) * 3]
 *
 *
 * ...
 * 1
 */
int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    // 每次消除 n-1个，剩余K个做最后一次消除

    if ((n - k) % (k - 1) != 0) {
        return -1;
    }

    /**
     * 1 2 3 4 5 6 -> sum =  21
     *
     *
     */
}