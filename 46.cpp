#include <iostream>
#include "dbg.h"
#include <vector>
#include <set>
using namespace  std;


void traverse(std::vector<int> &state,const std::vector<int>& nums, std::vector<std::vector<int>>& result){
        //3 1 2 -1 -1 -1 -1
        std::vector<int> remain(state.size(),-1);
        //[-1 1 1 1  -1 -1 -1]
        bool ok = true;
        int count = 0;
        for(int i = 0;i<state.size();i++){
            if(state[i] != -1){
                ++count;
                remain[state[i]] = 1;
            }else{
                ok = false;
            }
        }
        if(ok){
            for(int i = 0;i < state.size();i++){
               state[i] = nums[state[i]]; 
            }
            result.push_back(state);
            return;
        }
        for(int i = 0;i < remain.size();i++){
            if(remain[i] == -1){
                auto newState = state;
                newState[count] = i;
                traverse(newState,nums,result);
            }
        }        
}



vector<vector<int>> permute2(vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> state(nums.size(),-1);
    traverse(state,nums,result);
    return result;
}


int main(int argc, char const *argv[])
{
    std::vector<int> v = {4,9,0};
    auto r = permute(v);
    dbg(r);
    return 0;
}
