#include <string>
#include <vector>

#include "a.h"

using namespace std;

struct TrieNode {
    char c_ = 0;
    bool flag = false;
    std::map<char, TrieNode *> children_;
    explicit TrieNode(char c) : c_(c) {}
    TrieNode() = default;
};

namespace {
    void insertTrie(TrieNode *&node, const std::string &str, int index) {
        auto ch = str[index];
        auto iter = node->children_.find(ch);
        TrieNode *child = nullptr;
        if (iter == node->children_.end()) {
            child = new TrieNode(ch);
            node->children_[ch] = child;
        } else {
            child = iter->second;
        }
        if (index == str.length() - 1) {
            child->flag = true;
        } else {
            insertTrie(child, str, index + 1);
        }
    }

    bool searchTrie(TrieNode *&node, const std::string &str, int index) {
        auto ch = str[index];
        auto iter = node->children_.find(ch);
        if (iter == node->children_.end()) return false;
        if (index == str.length() - 1) {
            return iter->second->flag;
        }
        return searchTrie(iter->second, str, index + 1);
    }

    bool startWithTrie(TrieNode *&node, const std::string &str, int index) {
        auto ch = str[index];
        auto iter = node->children_.find(ch);
        if (iter == node->children_.end()) return false;
        if (index == str.length() - 1) return true;
        return startWithTrie(iter->second, str, index + 1);
    }

    void printTrie(TrieNode *&node, int index) {
        std::string space(index * 4 + 1, ' ');
        space += node->c_;
        printf("%s(%d)\n", space.c_str(), node->flag);
        for (auto &child : node->children_) {
            printTrie(child.second, index + 1);
        }
    }

    std::string minPrefix(TrieNode *&node, const std::string &str) {
        // 在Trie中找到str的最小前缀
    }

}  // namespace

class Trie {
   public:
    TrieNode *root;

    Trie() { this->root = new TrieNode(); }

    void insert(const string &word) { insertTrie(this->root, word, 0); }

    bool search(const string &word) { return searchTrie(this->root, word, 0); }

    bool startsWith(const string &prefix) { return startWithTrie(this->root, prefix, 0); }

    void print() { printTrie(this->root, 0); }
};

string replaceWords(vector<string> &dictionary, string sentence) {
    auto t = Trie();
    for (auto &d : dictionary) t.insert(d);

    return "";
}

int main() {
    std::vector<string> s{"cat", "bat", "ba", "ca", "rat", "bcf", "bam"};
    replaceWords(s, "Hello");

    return 0;
}
