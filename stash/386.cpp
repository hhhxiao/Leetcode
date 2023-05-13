#include <cstdio>
#include <vector>

using namespace std;

vector<int> lexicalOrder(int n) {
    // 1 10 100 1002

    int cnt = 0;
    int x = 1;
    std::vector<int> r(1, 1);
    while (r.size() < n) {
        if (x * 10 <= n) {
            x *= 10;
            r.push_back(x);
        } else {
            if (x >= n) x /= 10;
            x++;
            while (x % 10 == 0) x /= 10;
            r.push_back(x);
        }
        ++cnt;
    }
    return r;
}

int main() {
    auto r = lexicalOrder(30);
    for (auto i : r) {
        printf("%d ", i);
    }

    return 0;
}
