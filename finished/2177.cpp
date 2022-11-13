#include <vector>
using namespace std;
vector<long long> sumOfThree(long long num) {
    if(num % 3 != 0){
        return {};
    }
    int x = num / 3;
    return {x-1,x,x+1};
}
