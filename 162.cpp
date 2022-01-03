#include <cstdio>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    for (; begin < end;) {
        int mid = begin + (end - begin) / 2;
        if (nums[mid] > nums[mid + 1]) {
            end = mid;
        } else {
            begin = mid + 1;
        }
    }
    return begin;
}
int main(int argc, char const* argv[]) {
    std::vector<int> v = {1, 2, 3};
    printf("%d", findPeakElement(v));
    return 0;
}
