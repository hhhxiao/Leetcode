#include <cstdio>
#include <vector>

void mono_stack() {
    std::vector<int> v = {1, 3, 2, 5, 7, 6, 4};
    std::vector<int> stack;
    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        // 插入
        while (!stack.empty() && stack.back() < x) {
            printf("POP: %d\n", stack.back());
            stack.pop_back();
        }
        stack.push_back(x);
    }
    printf("In STACK:\n");
    for (int i = 0; i < stack.size(); i++) {
        printf("%d ", stack[i]);
    }
}

int main() {
    mono_stack();
    return 0;
}