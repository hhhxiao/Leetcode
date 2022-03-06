#include <string>
#include <vector>
using namespace std;
int countSubstrings(const std::string &s) {
    const int sz = s.size();
    if (sz <= 1) return sz;
    std::vector<std::vector<int>> status_array(sz, std::vector<int>(sz));
    int res = 0;
    for (int i = 0; i < sz; i++) {
        status_array[i][i] = 1;
        res++;
    }

    int l1 = 0, l2 = 0, cur_max_len = 1;
    for (int i = 0; i < sz - 1; i++) {
        if (s[i] == s[i + 1]) {
            res++;
            status_array[i][i + 1] = s[i] == s[i + 1];
            printf("[%s]\n", s.substr(i, 2).c_str());
        }
    }

    for (int current_len = 3; current_len <= sz; current_len++) {
        for (int j = 0; j <= sz - current_len; j++) {
            int begin_index = j;
            int end_index = j + current_len - 1;
            bool is = status_array[begin_index + 1][end_index - 1] &&
                      s[begin_index] == s[end_index];
            status_array[begin_index][end_index] = (int)is;
            if (is) {
                res++;
                printf("[%s]\n", s.substr(begin_index, current_len).c_str());
            }
        }
    }
    printf("res = %d", res);
    return res;
}

int main(int argc, char const *argv[]) {
    countSubstrings("aabacc");
    return 0;
}
