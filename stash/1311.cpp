#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include "a.h"

using namespace std;

vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                      vector<vector<int>>& friends, int id, int level) {
    std::vector<int> visit(watchedVideos.size(), 0);

    std::queue<std::pair<int, int>> q;

    std::unordered_map<std::string, int> view;
    visit[id] = 1;
    q.push({id, 0});
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top.second == level) {
            for (auto& v : watchedVideos[top.first]) {
                view[v]++;
            }
        }

        auto& fri = friends[top.first];

        if (top.second < level) {
            for (auto f : fri) {
                if (!visit[f]) {
                    q.push({f, top.second + 1});
                    visit[f] = 1;
                }
            }
        }
    }

    std::vector<pair<std::string, int>> res;
    for (auto& kv : view) res.push_back(kv);
    std::sort(res.begin(), res.end(),
              [](const pair<string, int>& p1, const pair<string, int>& p2) -> bool {
                  return p1.second < p2.second;
              });

    std::vector<string> r;
    for (auto& i : res) r.push_back(i.first);

    return r;
}

int main() {
    vector<vector<string>> videos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}};
    vector<vector<int>> f{{1, 2}, {0, 3}, {0, 3}, {1, 2}};
    dbg(watchedVideosByFriends(videos, f, 0, 1));

    return 0;
}