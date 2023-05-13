#include <string>
#include <vector>

using namespace std;

int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;
}

long long countVowels(string word) {
    std::vector<int> dp(word.size(), 0);

    size_t res = 0;
    // a b c e d f g
    // 0 1 2 3 4 5 6
    // 位置2开始的长度为4的字符串 = 位置2开始的长度为3的字符串 + word[2+4-1]
    //位置p开始的长度为q的字符串 = 位置p开始的长度为q-1的字符串+word[p+q-1]
    for (int len = 1; len <= word.size(); len++) {
        for (int p = 0; p < word.size() - len + 1; p++) {
            dp[p] += is_vowel(word[p + len - 1]);
            res += dp[p];
            printf("[%s : %d]", word.substr(p, len).c_str(), dp[p]);
        }
        printf("\n");
    }
    return res;
}
int main(int argc, char const *argv[]) {
    int num = countVowels("");
    printf("num = %d", num);
    return 0;
}
