#include <iostream>
#include <vector>

using namespace std;
string dayOfTheWeek(int day, int month, int year) {
    std::vector<std::string> weeks = {"Sunday",    "Monday",   "Tuesday",
                                      "Wednesday", "Thursday", "Friday",
                                      "Saturday"};
    if (month < 3) month += 12, year -= 1;
    int c = year / 100;
    year %= 100;
    int d =
        c / 4 - 2 * c + year + year / 4 + 13 * (month + 1) / 5 + day - 1 + 210;
    return weeks[d % 7];
}
