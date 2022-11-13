#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
vector<string> topKFrequent(vector<string>& words, int k) {
    std::unordered_map<std::string, size_t> map;
    for (int i = 0; i < words.size(); i++) {
        map[words[i]]++;
    }
    std::vector<std::pair<std::string, size_t>> pairs;
    for (auto& kv : map) {
        pairs.push_back({kv.first, kv.second});
    }
    std::partial_sort(pairs.begin(), pairs.begin() + k, pairs.end(),
                      [](const std::pair<std::string, size_t>& p1,
                         const std::pair<std::string, size_t>& p2) {
                          if (p1.second != p2.second) {
                              return p1.second > p2.second;
                          } else {
                              return p1.first < p2.first;
                          }
                      });
    std::vector<std::string> res;
    for (int i = 0; i < k; i++) {
        res.push_back(pairs[i].first);
    }
    return res;
}
int main(int argc, char const* argv[]) {
    std::vector<std::string> s = {"the", "day", "is",    "sunny", "the",
                                  "the", "the", "sunny", "is",    "is"};
    topKFrequent(s, 4);
    return 0;
}
