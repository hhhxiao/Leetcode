#include <iostream>
#include <vector>

using namespace std;
int maxChunksToSorted(vector<int>& arr) {
    int max = -1;
    int len = 0;
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        int v = arr[i];
        len++;
        if (max < v) {
            max = v;
        }
        if (max == len) {
            ++res;
            printf("%d\n", i);
        }
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> v{5, 4, 3, 2, 1, 6};
    maxChunksToSorted(v);
    return 0;
}
