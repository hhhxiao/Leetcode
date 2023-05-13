#include <algorithm>
#include <vector>

#include "dbg.h"

using namespace std;
int sumSubarrayMins(vector<int> &arr) {
    // 3 1 2 4
    // 3  [3]  --> (3)
    // 1  [3 1 2 4]  --> (31) (312) (3124) (1) (12) (124)
    // 2  [2 4] //   --> (2) (24)
    // 4  [4]-->      (4)
    // total  4*(4+1)/2 = 10

    //------------------------------------------------
    // 1 2 1 1
    // 1 [1 2 1 1] (1) (12) (121) (1211)
    // 2 [2]  (2)
    // 1 [2 1 1]   (21) (211)  (1) (11)
    // 1 [1]  (1)
    // TODO
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        int bi = i;
        int ai = i;
        while (bi >= 1 && arr[bi - 1] > arr[i]) bi--;
        while (ai < arr.size() && arr[ai] >= arr[i]) ai++;
        printf("%d: (%d-%d-%d)[", arr[i], bi, i, ai);
        for (int index = bi; index < ai; index++) {
            printf("%d ", arr[index]);
        }
        printf("] ");
        printf("%d * (%d * %d)\n", arr[i], (i - bi + 1), (ai - i));
        sum += arr[i] * (i - bi + 1) * (ai - i);
    }

    return sum;
}

int main() {
    std::vector<int> arr = {1, 1, 1, 1, 4, 532, 1, 2, 3, 41};

    printf("%d", sumSubarrayMins(arr));
    return 0;
}
