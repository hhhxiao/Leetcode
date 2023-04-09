#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int dp(uint16_t state, std::unordered_map<uint16_t, std::vector<int>>& table,
       const std::vector<std::vector<std::string>>& peple, size_t max) {
    // R(peolpe[0,i],S) = min(R(people[0,i-1],S), R(people[0,i-1], S - {people[i]} + 1 )
    // 简化 R(i,S) = min(R(i-1,S), R(i-1,S-p[i]) + 1)
    // i.  从req_skills到uint16_t内每一位的映射
}
vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
    std::unordered_map<std::string, int> idx;
    // 状态压缩
    uint16_t init_stat = 0;
    for (int i = 0; i < req_skills.size(); i++) {
        idx[req_skills[i]] = i;
        init_stat |= (1 << i);
    }

    std::unordered_map<uint16_t, std::vector<int>> table;
    dp(init_stat, table, people, people.size());
}