#include <vector>

#include "dbg.h"

using namespace std;

void change_line(std::vector<char>& vec) {
    vec.push_back('*');
    //[ ##.*.**.###.**_#__]
    int stone_ctr = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == '#') {
            stone_ctr++;
            vec[i] = ' ';
        } else if (vec[i] == '*') {
            for (int j = 0; j < stone_ctr; j++) {
                vec[i - 1 - j] = '#';
            }
            stone_ctr = 0;
        }
    }
    dbg(vec);
}

vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    std::vector<std::vector<char>> res = std::vector<std::vector<char>>(
        box[0].size(), std::vector<char>(box.size(), 0));

    for (auto& line : box) {
        change_line(line);
    }

    for (int i = 0; i < box.size(); i++) {
        for (int j = 0; j < box[0].size() - 1; j++) {
            res[j][i] = box[i][j];
        }
    }

    return res;
}
int main() {
    std::string line = "##  * *#* ##   ";
    std::vector<char> c(line.begin(), line.end());
    change_line(c);
    return 0;
}
