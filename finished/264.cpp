
#include <cstdio>
#include <set>

int nthUglyNumber(int n) {
    std::set<int> s;
    s.insert(1);

    int number = 0;
    while (number + s.size() < n) {
        auto first = s.begin();
        number++;
        s.insert(*first * 2);
        s.insert(*first * 3);
        s.insert(*first * 5);
        s.erase(first);
    }
    printf("Number = %d\n", number);
    auto iter = s.begin();
    std::advance(iter, n - number - 1);
    printf("res is %d", *iter);
    return 1;
}

int main() {
    nthUglyNumber(131);

    return 0;
}