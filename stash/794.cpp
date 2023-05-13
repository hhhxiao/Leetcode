#include <string>
#include <vector>
using namespace std;

void getwin(const vector<string>& b, int& x, int& o) {
    // row
    int win = 0;
    for (int i = 0; i < 3; i++) {
        if (b[i] == "OOO") o++;
        if (b[i] == "XXX") x++;
        if (b[0][i] == b[1][i] && b[1][i] == b[2][i] && b[0][i] != ' ') {
            if (b[0][i] == 'O') o++;
            if (b[0][i] == 'X') x++;
        }
    }

    if (b[0][0] == b[1][1] && b[1][1] == b[2][2] && b[0][0] != ' ') {
        if (b[0][0] == 'O') o++;
        if (b[0][0] == 'X') x++;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0] && b[0][2] != ' ') {
        if (b[0][2] == 'O') o++;
        if (b[0][2] == 'X') x++;
    }
}

bool validTicTacToe(vector<string>& board) {
    int wc = 0;
    int wx = 0;
    getwin(board, wx, wc);
    if (wc > 0 && wx > 0) return false;
    int x = 0;
    int o = 0;
    for (auto& s : board) {
        for (auto b : s) {
            if (b == 'O') o++;
            if (b == 'X') x++;
        }
    }
    if (wc == 0 && wx == 0) {
        return x == o || x == o + 1;
    } else if (wc + wx == 1) {
        return (x == o && wc == 1) || (x == o + 1 && wx == 1);
    } else if (wx == 2) {
        return x == 5 && o == 4;
    }

    return false;
}
