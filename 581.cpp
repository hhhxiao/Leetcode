#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int findUnsortedSubarray(vector<int>& nums) {
    auto sorted = nums;
    std::sort(sorted.begin(), sorted.end());
    int begin = 0;
    int end = nums.size() - 1;
    while (sorted[begin] == nums[begin]) begin++;
    while (sorted[end] == nums[end]) end--;

    printf("begin = %d end = %d", begin, end);
    return max(0, end - begin + 1);
}

int main() {
    std::vector<int> v = {2, 6, 4, 8, 10, 9, 15};

    findUnsortedSubarray(v);

    return 0;
}