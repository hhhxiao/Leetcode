#include <corecrt_math.h>
#include <float.h>

#include <unordered_map>

#include "a.h"

using namespace std;
bool isItPossible(string word1, string word2) {
    char c1[26]{0};
    char c2[26]{0};
    for (auto c : word1) c1[c - 'a']++;
    for (auto c : word2) c2[c - 'a']++;

    int num_c1 = 0;
    int num_c2 = 0;

    for (int i = 0; i < 26; i++) {
        if (c2[i] != 0) num_c2++;
        if (c1[i] != 0) num_c1++;
    }
    int c1_1 = 0;
    int c2_1 = 0;
    int c1_g1 = 0;
    int c2_g1 = 0;

    for (int i = 0; i < 26; i++) {
        if (c1[i] > 0 && c2[i] > 0) return true;
        if (c1[i] == 1) c1_1++;
        if (c1[i] > 1) c1_g1++;
        if (c2[i] == 1) c2_1++;
        if (c2[i] > 1) c2_g1++;
    }

    auto diff = abs(num_c1 - num_c2);
    if (diff == 0) {
        if (c1_g1 == 0 && c2_g1 == 0) return true;
        if (c1_1 == 0 && c2_1 == 0) return true;
        return false;
    } else if (diff == 1) {
        // s1 比 s2多一种：s1中存在出现一次的s2有 or s1中出现多次但s2没有
        if (num_c1 > num_c2) {
            for (int i = 0; i < 26; i++) {
                if (c1[i] == 1 && c2[i] > 0 || c1[i] > 1 && c2[i] == 0) return true;
            }
            return false;

        } else {
            for (int i = 0; i < 26; i++) {
                if (c2[i] == 1 && c1[i] > 0 || c2[i] > 1 && c1[i] == 0) return true;
            }
            return false;
        }
    } else if (diff == 2) {
        // s1中出现一次且s2中没出现过

        if (num_c1 > num_c2) {
            for (int i = 0; i < 26; i++) {
                if (c1[i] == 1 && c2[i] == 0) return true;
            }
            return false;
        } else {
            for (int i = 0; i < 26; i++) {
                if (c2[i] == 1 && c1[i] == 0) return true;
            }
            return false;
        }
    } else {
        return false;
    }
}
