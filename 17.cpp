#include <iostream>
#include <vector>
#include <string>
#include "dbg.h"
using namespace std;
 vector<string> letterCombinations(string digits) {
         vector<string> table{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };

    std::vector<std::string> res;

    int curLen = 0;
    for (auto &c: digits) {
        dbg(c);
        size_t idx = c - '0';
        auto number = table[idx];
        dbg(number);
        if(curLen == 0){
            for(auto &x : number){
                res.emplace_back(1,x);
            }
        }else{
            for(int i = 0;i < res.size();i++){
                dbg(res[i]);
                if(res[i].size() == curLen){
                    for(auto x:number){
                            res.push_back(res[i] + x);
                    }
                }
            }
        }
        dbg(res);
        ++curLen;
    }

    const int sz = digits.size();
    std::vector<std::string> r;
    for(int i = 0;i < res.size();i++){
        if(res[i].size() == sz){
            r.push_back(std::move(res[i]));
        }
    }
    return r;

}
    
int main(int argc, char const *argv[])
{
    dbg(letterCombinations("23"));
    return 0;
}
