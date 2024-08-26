#include "stats.h"
#include <vector>


struct Stats
{
    float average;
    float min;
    float max;
};


Stats Statistics::ComputeStatistics(const std::vector<float>& numbers) 
{
    Stats stats;

    //Empty then NaN
    if (numbers.empty()) {
        stats.average = NAN;
        stats.min = NAN;
        stats.max = NAN;
        return stats;
    }

    float sum = 0.0f;
    for (int i = 0; i < numbers.size(); i++) 
    {
        sum += numbers[i];
    }
    stats.average = sum / numbers.size();

    // Find min and max
    stats.min = numbers[0];
    stats.max = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] < stats.min) {
            stats.min = numbers[i];
        }
        if (numbers[i] > stats.max) {
            stats.max = numbers[i];
        }
    }

    return stats;
}
