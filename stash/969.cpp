#include <algorithm>
#include <iostream>
#include <vector>

#include "dbg.h"

using namespace std;

//交换[0,index]之间的位置
void pancake(std::vector<int>& v, int index) {
    int n = index / 2 + 1;
    for (int i = 0; i < n; i++) {
        std::swap(v[i], v[index - i]);
    }
}

void move_one(std::vector<int>& v, int index, int number, std::vector<int>& res) {
    int i = 0;
    while (v[i] != number) ++i;
    //首先换到第一个
    if (i != 0) {
        pancake(v, i);
        res.push_back(i + 1);
    }
    dbg(v);
    pancake(v, index);
    res.push_back(index + 1);
}
vector<int> pancakeSort(vector<int>& arr) {
    auto sorted = arr;
    std::vector<int> res;
    std::sort(sorted.begin(), sorted.end());
    dbg(arr);
    for (int i = sorted.size() - 1; i >= 0; i--) {
        if (arr[i] != sorted[i]) {
            move_one(arr, i, sorted[i], res);
        }
        dbg(arr);
    }
    return res;
}
int main() {
    std::vector<int> v{3, 2, 4, 1};
    auto x = pancakeSort(v);
    dbg(x);
    return 0;
}