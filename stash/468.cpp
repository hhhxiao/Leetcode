#include <stdio.h>

#include <vector>

#include "a.h"

using namespace std;

bool validipv4(const std::vector<int>& v) {
    if (v.empty()) return false;
    if (v[0] == 0 && v.size() > 1) return false;
    int x = 0;
    for (auto i : v) x = (x * 10 + i);
    return x >= 0 && x <= 255;
}

string validIPAddress(string queryIP) {
    int nums = 0;
    int AF = 0;
    int colon = 0;
    int dot = 0;
    int others = 0;
    for (auto c : queryIP) {
        if (c >= '0' && c <= '9') {
            nums++;
        } else if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
            AF++;
        } else if (c == ':') {
            colon++;
        } else if (c == '.') {
            dot++;
        } else {
            others++;
        }
    }

    if (others > 0) {
        return "Neither";
    }

    if (dot > 0 && colon > 0) return "Neither";

    if (dot > 0) {  // ipv4
        if (dot != 3 || AF > 0) return "Neither";
        vector<int> cs;
        for (auto c : queryIP) {
            if (c >= '0' && c <= '9') {
                cs.push_back(c - '0');

            } else if (c == '.') {
                if (!validipv4(cs)) return "Neither";
                cs.clear();
            }
        }
        if (!validipv4(cs)) return "Neither";
        return "IPv4";
    }
    if (colon > 0) {
        if (colon != 7) return "Neither";
        int len = 0;
        for (auto c : queryIP) {
            if (c == ':') {
                if (len == 0 || len > 4) return "Neither";
                len = 0;
            } else {
                len++;
            }
        }
        if (len == 0 || len > 4) return "Neither";
        return "IPv6";
    }

    return "Neither";
}

int main() {
    dbg(validIPAddress("2001:0db8:85a3:0:0:8A1E:0370:"));
    return 0;
}