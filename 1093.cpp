#include <iostream>
#include <vector>

#include "dbg.h"
using namespace std;

vector<double> sampleStats(vector<int>& count) {
    int sum = 0;
    int max_value_index = -1;
    int min_value_idx = -1;
    int most_times = count[0];
    int most_times_idx = 0;
    int number_ctr = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            number_ctr += count[i];
            max_value_index = i;
            if (min_value_idx != -1) {
                min_value_idx = i;
            }
            if (count[i] > most_times) {
                most_times_idx = i;
            }
        }
        sum += count[i] * i;
    }

    return {static_cast<double>(min_value_idx),
            static_cast<double>(max_value_index),
            static_cast<double>(sum) / number_ctr, 0.0,
            static_cast<double>(most_times_idx)};
}
