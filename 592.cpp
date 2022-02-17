#include <string>
#include <vector>
using namespace std;
string fractionAddition(string expression) {
    if (expression.empty()) {
        return "";
    }
    if (expression[0] == '+' || expression[0] == '-') {
        expression = "0/1" + expression;
    }

    return "";
}
