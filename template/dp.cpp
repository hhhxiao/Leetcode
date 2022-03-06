#include <iostream>
#include <vector>

void simple_array_dp() {
    std::vector<int> nums;
    std::vector<int> dp(nums.size(), 0);
    for (int len = 1; len <= nums.size(); len++) {
        printf("Current len is %d\n", len);
        for (int start = 0; start <= nums.size() - len; start++) {
            printf("Proecss slice num[%d %d]\n", start, start + len - 1);
        }
    }
}

void db_substring(const std::string &s) {
    const int sz = s.size();

    // status_array[i][j]表示s从i到j的切片
    std::vector<std::vector<int>> status_array(sz, std::vector<int>(sz));

    for (int i = 0; i < sz; i++) {
        status_array[i][i] = 1;
    }

    for (int i = 0; i < sz - 1; i++) {
        status_array[i][i + 1] = s[i] == s[i + 1];
        printf("[%s]\n", s.substr(i, 2).c_str());
    }

    for (int current_len = 3; current_len <= sz; current_len++) {
        for (int j = 0; j <= sz - current_len; j++) {
            int begin_index = j;
            int end_index = j + current_len - 1;
            // TODO
            status_array[begin_index][end_index] = 1;
        }
    }
}