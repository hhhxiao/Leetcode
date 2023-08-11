#include <string>
#include <type_traits>
#include <vector>

#include "a.h"

using namespace std;

vector<string> removeComments(vector<string>& source) {
    if (source.empty()) return {};
    std::string buffer;
    for (int i = 0; i < source.size() - 1; i++) {
        buffer += source[i] + "\n";
    }
    buffer += source.back();

    std::string bf2;
    bool in_block{false};
    int i = 0;
    while (i < buffer.size()) {
        if (in_block) {
            // end found
            if (buffer[i] == '*' && i + 1 < buffer.size() && buffer[i + 1] == '/') {
                i += 2;
                in_block = false;
            } else {
                i++;
            }
        } else {
            if (buffer[i] == '/' && i + 1 < buffer.size() && buffer[i + 1] == '*') {
                in_block = true;
                i += 2;
            } else {
                bf2.push_back(buffer[i]);
                i++;
            }
        }
    }

    // process line (remove //+)

    std::vector<std::string> src2;
    std::string line;
    for (auto i : bf2) {
        if (i == '\n') {
            auto it = line.find("//");
            if (it != std::string::npos) {
                line = line.substr(0, it);
            }
            if (!line.empty()) {
                src2.push_back(line + "\n");
            }
            line.clear();
        } else {
            line.push_back(i);
        }
    }

    if (!line.empty()) {
        src2.push_back(line);
    }

    if (!src2.empty() && src2.back().back() == '\n') {
        src2.back().pop_back();
    }
    for (auto& line : src2) {
        printf("%s", line.c_str());
    }

    return src2;
}

int main() {
    std::vector<std::string> srcs{

        "void func(int k) {",                //
        "// this function does nothing /*",  //
        " k = k*2/4;",                       //
        "   k = k/2;*/",                     //
        "}"                                  //

    };

    removeComments(srcs);
    return 0;
}
