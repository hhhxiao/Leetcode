#include <bitset>
#include <string>
#include <vector>

using namespace std;

unsigned long str2ul(const std::string& str) {
    std::bitset<26> bits;
    for (int j = 0; j < str.size(); j++) {
        bits.set(str[j] - 'a');
    }
    printf("%s: [%s]\n", str.c_str(), bits.to_string().c_str());
    return bits.to_ulong();
}

int maxProduct(vector<string>& words) {
    std::vector<unsigned long> list;
    std::vector<size_t> lens;
    for (int i = 0; i < words.size(); i++) {
        list.push_back(str2ul(words[i]));
        lens.push_back(words.size());
    }
    int max = 0;
    for (int i = 0; i < list.size() - 1; i++) {
        for (int j = i + 1; j < list.size(); j++) {
            if ((list[i] & list[j]) == 0) {
                auto mul = lens[i] * lens[j];
                if (max < mul) {
                    max = mul;
                }
            }
        }
    }

    return max;
}

int main(int argc, char const* argv[]) { return 0; }
