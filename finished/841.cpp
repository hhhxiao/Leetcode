#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
bool canVisitAllRooms(vector<vector<int>>& rooms) {
    std::vector<int> flags(rooms.size(), 0);
    std::stack<int> stack;
    stack.push(0);
    while (!stack.empty()) {
        auto room = stack.top();
        stack.pop();
        flags[room] = 1;
        for (int i = 0; i < rooms[room].size(); i++) {
            if (flags[rooms[room][i]] == 0) {
                stack.push(rooms[room][i]);
            }
        }
    }

    return std::all_of(flags.begin(), flags.end(),
                       [](int v) { return v == 1; });
}