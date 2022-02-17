#include <corecrt.h>
#include <stdio.h>

#include <algorithm>
#include <cstdio>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <vector>

using namespace std;
int numRescueBoats(vector<int>& people, int limit) {
    if (people.empty()) return 0;
    std::map<int, int> m;
    for (int i = 0; i < people.size(); i++) {
        m[people[i]]++;
    }
    int count = 0;
    while (!m.empty()) {
        auto p = m.rbegin();
        printf("%d个%dkg的人\n", p->second, p->first);
        if (m.size() == 1) {
            printf("体重都一样了");
            count += p->first * 2 <= limit ? (p->second + 1) / 2 : p->second;
        }

        int remain = limit - p->first;
        auto iter = m.upper_bound(remain);
        if (iter == m.begin()) {
            printf("船坐不下其他人了\n");
            count += p->second;
            m.erase(p->first);
        } else if (iter == m.end()) {
            printf("一次坐两个一样重的\n");
            int w = p->first;
            int cnt = p->second;
            count += p->second / 2;
            m.erase(p->first);
            if (cnt % 2 == 1) {
                m[w] = 1;
            }
        } else {
            iter = std::prev(iter);
            printf("%d和%d坐%d船\n", p->first, iter->first,
                   min(iter->second, p->second));
            if (iter->second > p->second) {
                count += p->second;
                m[iter->first] = iter->second - p->second;
                m.erase(p->first);
            } else if (iter->second == p->second) {
                count += p->second;
                m.erase(p->first);
                m.erase(iter);
            } else if (iter->second < p->second) {
                count += iter->second;
                m[p->first] = p->second - iter->second;
                m.erase(iter);
            }
        }
        // 4 4 4 4 4 4  8
    }

    return count;
}

int main() {
    std::vector<int> v{1, 1, 2, 3, 4};
    numRescueBoats(v, 5);
}
