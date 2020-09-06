#include "stats.h"
#include <math.h>
#include <algorithm>

Stats Statistics::ComputeStatistics(const std::vector<double>& sample) {
    Stats stats_obj;
    stats_obj.ComputeAverage(sample);
    stats_obj.ComputeMax(sample);
    stats_obj.ComputeMin(sample);
    return stats_obj;
}

void Stats::ComputeAverage(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::average = (double)NAN;
    }
    else
    {
        double sum = 0;
        int sample_size = 0;
        for (double element : sample)
        {
            if (!isnan(element))
            {
               sum += element;
               sample_size += 1;
            }
        }
        Stats::average = sum / sample_size;
    }
}

void Stats::ComputeMax(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::max = (double)NAN;
    }
    else
    {
        Stats::max = *std::max_element(sample.begin(), sample.end());
    }
}

void Stats::ComputeMin(const std::vector<double>& sample)
{
    if (sample.empty())
    {
        Stats::min = (double)NAN;
    }
    else
    {
        Stats::min = *std::min_element(sample.begin(), sample.end());
    }
}
