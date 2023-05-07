

#include <vector>
using namespace std;
#include <array>
#include <unordered_set>

#include "dbg.h"

vector<int> distinctDifferenceArray(vector<int>& nums) {
    std::vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        unordered_set<int> s1(nums.begin(), nums.begin() + i + 1);
        unordered_set<int> s2(nums.begin() + i + 1, nums.end());
        v.push_back(s1.size() - s2.size());
    }
    return v;
}
class FrequencyTracker {
    vector<int> ctr;
    vector<int> freq;

   public:
    FrequencyTracker() {
        ctr = vector<int>(10001, 0);
        freq = vector<int>(20001, 0);
    }
    void add(int number) {
        ctr[number]++;
        freq[ctr[number] - 1]--;
        freq[ctr[number]]++;
    }

    void deleteOne(int number) {
        if (ctr[number] == 0) return;
        ctr[number]--;
        freq[ctr[number] + 1]--;
        freq[ctr[number]]++;
    }
    bool hasFrequency(int frequency) { return freq[frequency] > 0; }
};

int cal(vector<int>& v, int c) {
    int e = 0;
    if (c - 1 >= 0 && v[c - 1] == v[c] && v[c] != 0) e++;
    if (c + 1 < v.size() && v[c + 1] == v[c] && v[c] != 0) e++;
    return e;
}

vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
    std::vector<int> board(n, 0);
    std::vector<int> r;
    int same = 0;

    for (int i = 0; i < queries.size(); i++) {
        // 计算之前有几个
        int last = cal(board, queries[i][0]);
        board[queries[i][0]] = queries[i][1];
        int now = cal(board, queries[i][0]);
        same += (now - last);

        r.push_back(same);
    }

    return r;
}
#include <map>
#include <vector>
void traverse_path(int n) {
    do {
        printf("%d->", n);
        n = (n - 1) >> 1;
    } while (n > 1);
    printf("%d->", n);
}

void init_sum(int s, int sum, vector<int>& cost, map<int, vector<int>>& value) {
    sum += cost[s];
    if (s >= cost.size() / 2) {  // leaft
        value[sum].push_back(s);
    } else {
        int r = (s + 1) * 2;
        int l = (s + 1) * 2 - 1;
        init_sum(r, sum, cost, value);
        init_sum(l, sum, cost, value);
    }
}

int minIncrements(int n, vector<int>& cost) {
    int v = 0;
    int fl = cost.size() / 2;
    std::map<int, vector<int>> ma;
    int sum = 0;
    init_sum(0, sum, cost, ma);
    std::vector<int> path_ctr(cost.size(), 0);
    path_ctr[0] = ma.rbegin()->first;
    // dbg(ma);
    int max = path_ctr[0];
    for (auto i = ma.rbegin(); i != ma.rend(); i++) {
        for (auto node : i->second) {
            // dbg(node);
            // dbg(path_ctr);
            // 计算该路径上的数的和
            int path_sum = 0;
            int r = node;
            do {
                path_sum += cost[r];
                r = (r - 1) >> 1;
            } while (r > 0);
            path_sum += cost[0];
            // printf("%d -> sum = %d", node, path_sum);

            int select = node;
            do {
                if (path_ctr[select] == max) {
                    break;
                } else {
                    path_ctr[select] = max;
                }
                select = (select - 1) >> 1;
            } while (true);
            v += (max - path_sum);
            cost[select] += max - path_sum;
        }
    }
    return v;
}

int main() {
    std::vector<int> tree{5, 3, 3};
    dbg(minIncrements(3, tree));
    return 0;
}