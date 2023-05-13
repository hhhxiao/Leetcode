#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;
void reverse_between(vector<int>& array, int begin, int end) {
    while (begin < end) {
        int temp = array[begin];
        array[begin] = array[end];
        array[end] = temp;
        ++begin;
        --end;
    }
}
void rotate(vector<int>& nums, int k) {
    k = nums.size() - k;
    reverse_between(nums, 0, k - 1);
    reverse_between(nums, k, nums.size() - 1);
    reverse_between(nums, 0, nums.size() - 1);
}

int main(int argc, char const* argv[]) {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    rotate(v, 3);
    dbg(v);
    return 0;
}
