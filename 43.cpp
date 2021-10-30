#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "dbg.h"
using namespace std;
string multiply(string num1, string num2) {
        
        std::vector<int> n1(num1.size());
        std::vector<int > n2(num2.size());
        for(int i = 0; i < num1.size();i++){
            n1[i] = num1[i] - '0';
        }
        for(int i = 0;i < num2.size();i++){
            n2[i] = num2[i] - '0';
        }
        dbg(n2);
        dbg(n1);
        std::vector<std::vector<int>> ready_to_add;
        int max_size = 0;
        int zero_idx = 0;
        for(int i = n2.size()-1;i >=0;i--){
            //从后往前遍历n2的每一个数字
            std::vector<int> res(zero_idx,0);
            dbg(res,res);
            zero_idx++;
            int borrow = 0;
            for(int j = n1.size()-1;j >=0;j--){
                int val = n2[j]* n1[j] + borrow;
                dbg(val);
                res.push_back(val % 10);
                borrow = val / 10;
            }
            dbg(borrow);
            if(borrow!=0)
                res.push_back(borrow);
            if(max_size < res.size()){
                max_size = res.size();
            }
            dbg(res);
            ready_to_add.push_back(res);
        }

        std::vector<int> r;
        r.reserve(max_size+1);
        int carry = 0;
        for(int i = 0;i < max_size;i++){
            int sum = carry;
            for(int j = 0;j < ready_to_add.size();j++){
                auto s = ready_to_add[j];
                if(s.size() > i){
                    sum += s[i];
                }
            }

            r.push_back(sum % 10);
            carry = sum / 10;
        }

        if(carry !=0)
            r.push_back(carry);

        std::string a;
        a.reserve(r.size());
        for(int  i = r.size()-1;i>=0;i--){
            a.push_back(static_cast<char>(r[i]+'0'));
        }
        dbg(r);
        dbg(a);
        return a;
    
}
 std::map<int,std::set<int>> SpiltChunksToPiece(const std::vector<int>& chunk_list_ ,size_t n,float rate){
        if(n * rate > 1){
         n = static_cast<int>(0.5/rate);   
        }
        auto totalSize = chunk_list_.size();
        int l = static_cast<int>(totalSize * rate * 0.5);
        std::map<int,std::set<int>> res;
        for (size_t i = 0; i < n; i++){
                int start_1 = i * l;
                for (int idx = 0; idx < l; idx++)
                {
                    int x = i * l + idx;
                    res[i].insert(chunk_list_[x]);
                    res[i].insert(chunk_list_[totalSize-1-x]);
                }       
        }
        return res;

    }
int main(int argc, char const *argv[])
{   
    std::vector<int> r;
    for (size_t i = 0; i < 1000; i++)
    {
        r.push_back(i);
    }
    auto c = SpiltChunksToPiece(r,5,0.02);
    for(const auto&kv:c){
        printf("===%d===\n",kv.first);
        for(auto &i:kv.second){
            printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}