#include "stats.h"
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<double>& sample) {
    Stats stats_obj;
    stats_obj.ComputeAverage(sample);
    stats_obj.ComputeMax(sample);
    stats_obj.ComputeMin(sample);
    return stats_obj;
}

void Stats::ComputeAverage(const std::vector<double>& sample)
{
    
    if(sample.size() == 0) 
    {
        Stats::average = NAN;
    }
    else
    {
        double sum = 0;
        for(double element : sample)
        {
            if(element != NAN)
                sum += element;
        }
        Stats::average = sum/sample.size();
    }  
}

void Stats::ComputeMax(const std::vector<double>& sample)
{
    Stats::max = sample[0];
    if(sample.size() == 0)
    {
        Stats::max = NAN;
    }  
    else
    {
        for(double element : sample)
        {
            if(element > Stats::max) Stats::max = element;
        }
    }
}

void Stats::ComputeMin(const std::vector<double>& sample)
{
    Stats::min = sample[0];
    if(sample.size() == 0)
    {
        Stats::min = NAN;
    }
    else
    {
        for(double element : sample)
        {
            if(element < Stats::min) Stats::min = element;
        }
    }
}
