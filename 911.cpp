#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "dbg.h"

using namespace std;
class TopVotedCandidate {
   private:
    std::map<int, int> votes;

   public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        for (int i = 0; i < times.size(); i++) {
            votes[times[i]] = persons[i];
        }
    }

    int q(int t) {
        dbg(votes);
        auto iter = this->votes.upper_bound(t);
        std::map<int, int> ctr;
        for (auto it = votes.begin(); it != iter; it++) {
            ctr[it->second]++;
        }
        dbg(ctr);
        int max_votes = INT32_MIN;
        for (auto kv : ctr) {
            if (max_votes < kv.second) {
                max_votes = kv.second;
            }
        }
        dbg(max_votes);
        do {
            std::advance(iter, -1);
            auto res = ctr.find(iter->second);
            if (res->second == max_votes) {
                return res->first;
            }
        } while (iter != votes.begin());
        return -1;
    }
};

int main() {
    std::vector<int> p = {0, 1, 1, 0, 0, 1, 0};
    std::vector<int> v = {0, 5, 10, 15, 20, 25, 30};

    TopVotedCandidate tvc(p, v);

    std::cout << tvc.q(3) << std::endl;
    std::cout << tvc.q(12) << std::endl;
    std::cout << tvc.q(25) << std::endl;
    std::cout << tvc.q(15) << std::endl;
    std::cout << tvc.q(24) << std::endl;
    std::cout << tvc.q(8) << std::endl;

    return 0;
}
