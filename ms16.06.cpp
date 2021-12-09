#include <map>
#include <set>
#include <vector>

using namespace std;

int smallestDifference2(vector<int>& a, vector<int>& b) {
    std::map<int, int> m;
    for (int i = 0; i < a.size(); i++) {
        m[a[i]] = 1;
    }
    for (int i = 0; i < b.size(); i++) {
        m[b[i]] = 0;
    }

    auto first = m.begin();
    int min = INT32_MAX;
    for (auto it = std::next(m.begin()); it != m.end(); it++) {
        if (it->second != first->second) {
            int diff = it->first - first->first;
            if (min > diff) min = diff;
        }
        first = it;
    }
    return min;
}

int main(int argc, char const* argv[]) {
    std::vector<int> a = {1, 3, 15, 11, 2}, b = {23, 127, 235, 19, 8};
    auto v = smallestDifference2(a, b);
    printf("v = %d ", v);
    return 0;
}
