#include <iostream>
#include <algorithm>
#include <vector>
#include "dbg.h"
using namespace std;
    




vector<int> searchRange(vector<int>& nums, int target) {
    auto idx1 = std::lower_bound(nums.begin(),nums.end(),target);
    auto idx2 = std::upper_bound(nums.rbegin(),nums.rend(),target,[](int x1,int x2){
            return x1 >= x2;
    });
    int r1  =0,r2 = 0;
    if(idx1 == nums.end()){
        return {-1,-1};
    }else{
        r1 = std::distance(nums.begin(),idx1);
        r2 = nums.size()-1 - std::distance(nums.rbegin(),idx2); 
        return {r1,r2};
    }
}

int main(int argc, char const *argv[])
{
    std::vector<int> v{-1,0,1,2,3,3,3,3,3,3,3,4,7};
    auto r =  searchRange(v,3);
    dbg(r);
    return 0;
}
