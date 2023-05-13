#include <cstdio>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

template <class ForwardIt, class T>
ForwardIt upper_bound(ForwardIt first, ForwardIt last, const T& value) {
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);

    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (!(value < *it)) {
            first = ++it;
            count -= step + 1;
        } else
            count = step;
    }
    return first;
}

class RangeFreqQuery {
    std::unordered_map<int, std::vector<int>> table;

   public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            table[arr[i]].push_back(i);
        }
    }
    int query(int left, int right, int value) {
        auto s = table.find(value);
        if (s == table.end()) {
            return 0;
        }
        auto& vec = s->second;
        auto iter1 = std::lower_bound(vec.begin(), vec.end(), left);
        auto iter2 = upper_bound(vec.begin(), vec.end(), right);
        return std::distance(iter1, iter2);
    }
};

int main() {
    const char* str = "qaq";
    const char* s2 = "tnt";
    str = s2;
    printf("%s", str);
    // 2
    // std::vector<int> v{12, 33, 4, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};
    // RangeFreqQuery f(v);
    // printf("%d", f.query(3, 3, 4));
    return 0;
}