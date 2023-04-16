#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
#include "dbg.h"
#include "io/io.h"
#include "template/prints.h"
#include <numeric>
#include <vector>
#include <map>
#include <deque>

#include <queue>
class Solution {
public:
    std::unordered_map<int,std::vector<int>>  tree;
    std::vector<int> prices;
    std::vector<int> ctr;


    std::vector<int> getPath(int from, int to){
        std::vector<int> path;
        std::vector<int> vis(this->prices.size(),0);
        std::queue<int> q;
        std::map<int,int> path_cache;
        
        q.push(from);
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if(cur == to)break;
            vis[cur] = 1; 
            auto &nexts = tree[cur];
            for(auto next :nexts){
                if(!vis[next]){
                    path_cache[next]  = cur;
                    q.push(next);
                }
            }
        }
        
        int st = to;
        path.push_back(st);        
        while (st != from)
        {
            st = path_cache[st];
            path.push_back(st);   
        }
        return path;
    } 
    
    int dp(const std::vector<int> &cur, std::map<std::vector<int>,int>& status){
        int ct = 0;
        int index = 0;
        for(auto i = 0;i < cur.size();i++){
            if(cur[i] != 0){
                ct++;
                index = i;
            }
        }

        if(ct == 1){
            return ctr[index] * prices[index] / 2;
        }


        auto  it = status.find(cur);
        if(it != status.end())return it->second;
        
        int select = 0;
        while(cur[select] == 0)++select;
        //选第一个
        auto h1 = cur;
        h1[select]  = 0;
        auto h2 = h1;
        auto nexts = tree[select];
        for(auto & next: nexts)h1[next] = 0;
        
        auto p1 =  ctr[select] * prices[select] / 2 + dp(h1,status);
        auto p2 = dp(h2,status);
        return min(p1,p2);
    }

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    prices = price;
    ctr = std::vector<int> (price.size(),0);

        for(auto & edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }      

        for(auto & trip: trips){
            auto path = this->getPath(trip[0],trip[1]);
            for(auto p: path){
                ctr[p]++;
            }
        }

        std::vector<int> s(price.size(),1);
        std::map<std::vector<int>,int> status;
        return dp(s, status);
    }


};





int main() {
    std::vector<std::vector<int>> edges {{0,1},{1,2},{1,3}};
    std::vector<int> prices{2,2,10,6};
    std::vector<std::vector<int>> trips {{0,3},{2,1},{2,3}};
    Solution s;
   std::cout<< s.minimumTotalPrice(4, edges,prices,trips);
    return 0;
}
