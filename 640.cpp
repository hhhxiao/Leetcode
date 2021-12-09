#include <iostream>
#include <string>
using namespace std;

std::pair<int, int> getPol(const std::string& pol) {
    printf("Pol is [%s]\n", pol.c_str());
    int nx = 0, nc = 0;
    bool is_x = false;
    bool is_neg = false;
    bool number_appear = false;
    int value = 0;
    for (int i = 0; i < pol.size(); i++) {
        char c = pol[i];
        if (c == '-' || c == '+') {
            if (!number_appear && is_x && value == 0) {
                value = 1;
            }

            if (is_neg) value *= -1;
            is_x ? nx += value : nc += value;
            is_x = false;
            is_neg = c == '-' ? true : false;
            number_appear = false;
            value = 0;
        } else {
            if (c >= '0' && c <= '9') {
                number_appear = true;
                value = value * 10 + (c - '0');
            } else if (c == 'x') {
                is_x = true;
            }
        }
    }

    printf("%d x + %d\n", nx, nc);
    return {nx, nc};
}
string solveEquation(const string& equation) {
    auto p_eq = equation.find("=");
    auto pl = getPol(equation.substr(0, p_eq) + "+");
    auto pr = getPol(equation.substr(p_eq + 1) + "+");

    if (pl.first == pr.first) {
        return pl.second == pr.second ? "Infinite solutions" : "No solution";
    } else {
        int res = (pr.second - pl.second) / (pl.first - pr.first);
        return "x=" + std::to_string(res);
    }
}
int main(int argc, char const* argv[]) {
    std::cout << solveEquation("3x-3=0");
    return 0;
}
