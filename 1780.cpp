#include <algorithm>
#include <iostream>
#include <vector>
#include "dbg.h"
bool checkPowersOfThree(int n) {       

  std::vector<int> res;
  while (n >= 3) {
    res.push_back(n % 3);
    n /= 3;
  }
  res.push_back(n);
  dbg(res);
  return std::all_of(res.begin(),res.end(),[](int x){
        return x == 1 || x == 0;
      });
}


int main(){
  checkPowersOfThree(91);
  return 0;
}
