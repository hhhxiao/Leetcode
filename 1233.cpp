#include <iostream>
#include <vector>
using namespace std;

struct Tree {
    std::string node;
    bool exit = false;
    std::vector<Tree*> leafs;
};

vector<string> removeSubfolders(vector<string>& folders) {
    for (auto& folder : folders) {
    }
}
