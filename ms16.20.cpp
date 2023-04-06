#include <string>
#include <vector>

using namespace std;
vector<string> getValidT9Words(string num, vector<string>& words) {
    // 计算words的哈希
    const int cm[] = {
        2, 2, 2,     //
        3, 3, 3,     //
        4, 4, 4,     //
        5, 5, 5,     //
        6, 6, 6,     //
        7, 7, 7, 7,  //
        8, 8, 8,     //
        9, 9, 9      //
    };
    std::vector<std::string> res;
    for (int i = 0; i < words.size(); i++) {
        auto s = std::string();

        const auto& w = words[i];
        for (auto c : w) {
            s += 'a' + cm[c - 'a'];
        }
        if (s == num) {
            res.push_back(w);
        }
    }
    return res;
}
int main() { return 0; }
