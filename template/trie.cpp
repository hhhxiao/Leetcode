#include <cstdio>
struct trie {
    int nex[10000][26], cnt;
    bool exist[10000];  // 该结点结尾的字符串是否存在

    void insert(const char *s, int l) {  // 插入字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
            p = nex[p][c];
        }
        exist[p] = 1;
    }

    bool find(const char *s, int l) {  // 查找字符串
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return exist[p];
    }
};
int main() {
    trie t;
    t.insert("abc", 3);
    printf("%d", t.find("abc", 3));
    printf("t");
    return 0;
}
