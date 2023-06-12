#include <string>
#include <tuple>

#include "a.h"

using namespace std;

std::tuple<std::string, std::string> sp(const std::string& log) {
    auto it = log.find_first_of(' ');
    return std::make_tuple(std::string(log.begin(), log.begin() + it), std::string(log.begin() + it + 1, log.end()));
}

vector<string> reorderLogFiles(vector<string>& logs) {
    std::stable_sort(logs.begin(), logs.end(), [&](const std::string& l1, const std ::string& l2) {
        auto [lable1, content1] = sp(l1);
        auto [lable2, content2] = sp(l2);
        char t1 = l1.back() >= '0' && l1.back() <= '9' ? 'N' : 'C';
        char t2 = l2.back() >= '0' && l2.back() <= '9' ? 'N' : 'C';
        if (t1 != t2) return t1 < t2;
        if (t1 == 'N') return t1 < t2;
        if (t1 == 'C') {
            if (content1 != content2) return content1 < content2;
            return lable1 < lable2;
        }
        return true;
    });

    return logs;
}

int main() {
    std::string log = "dig1 8 1 5 1";
    auto [label, content] = sp(log);
    dbg("[" + label + "]");
    dbg("[" + content + "]");
}
