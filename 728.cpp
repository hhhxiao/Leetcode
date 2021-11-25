#include <cstdio>
#include <vector>

using namespace std;
bool isSelfDivice(int v) {
    int ori = v;
    while (v > 0) {
        auto m = v % 10;
        if (m == 0 || ori % m != 0) {
            return false;
        }
        v /= 10;
    }
    return true;
}
vector<int> selfDividingNumbers(int left, int right) {
    std::vector<int> v;
    for (int i = left; i <= right; i++) {
        if (isSelfDivice(i)) {
            v.push_back(i);
        }
    }
    return v;
}

int main(int argc, char const *argv[]) {
    //    printf("%d", isSelfDivice(10));
    // auto v = selfDividingNumbers(0, 22);
    // for (auto i : v) {
    //     printf("%d ", i);
    // }
    // printf("\n");
    printf("%d", 10 % 0);
    return 0;
}
