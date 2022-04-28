#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include "dbg.h"
using namespace   std;

void traverseStack(int sz,int current,int max,std::string &s,std::vector<std::string>& res){
  //  dbg(v);
    if(current > max){
        s += std::string(sz,')');
        dbg(s);
        res.push_back(s);
        return;
    }
    std::string r = s;
    s += "(";
    traverseStack(sz+1,current+1,max,s,res);
    if(sz > 0){
         r += ")";
         traverseStack(sz-1,current,max,r,res);
     }
}

vector<string> generateParenthesis(int n) {
    std::vector<std::string> r;
    std::string str = "(";

    traverseStack(1,2,n,str,r);

    return r;
}

int main(int argc, char const *argv[])
{
    dbg(generateParenthesis(6));
    return 0;
}
