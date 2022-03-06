#include <algorithm>
#include <string>
#include <vector>

using namespace std;
string largestTimeFromDigits(vector<int>& arr) {
    int max = -1;
    for (int i = 0; i < 24; i++) {
        std::next_permutation(arr.begin(), arr.end());
        int x = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
        if (x / 100 <= 23 && x % 100 < 60 && x > max) {
            max = x;
        }
    }
    if (max == -1) {
        return "";
    }
    auto hour = std::to_string(max / 100);
    if (hour.size() == 1) {
        hour = "0" + hour;
    }
    auto min = std::to_string(max % 100);
    if (min.size() == 1) {
        min = "0" + min;
    }
    return hour + ":" + min;
}

int main() {
    std::vector<int> v = {0, 1, 0, 0};
    printf("%s", largestTimeFromDigits(v).c_str());
}