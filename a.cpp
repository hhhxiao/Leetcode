#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
int main(int argc, char const *argv[]) {
    int age = 0;
    scanf("%d", &age);
    printf("==================\n");
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each(v.begin(), v.end(), [=](int val) {
        if (val > age) {
            printf("%d\n", val);
        }
    });
    return 0;
}
