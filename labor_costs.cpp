//
// Created by Ellie Sheppard on 10/3/25.
//

#include "labor_costs.h"
// take in number of indoor(stalled) horses, add 1.5 min of labor per hour of stalling a day to base labor of 30 mins + 10 extra per horse.
// add 10 min per horse per day if paddocks are picked. subtract that 10 mins per horse that is in 24/7.
// if full training, add 1 hour of labor costs per day. assume labor costs are 15.00/hour for cleaning, 25.00 for training unless user inputs otherwise
// prompt by how many hours is " " (from list of horses in feed costs) stalled per day. then ask for # in training
double labor_costs::calc_daily_labor (int num_horses, const std::vector<int>& stalled_hours,
        int num_in_training, bool paddocks_picked) {
    double total_cleaning_mins = 30 + (10 * num_horses); // set baseline 30 mins (travel to and from, getting set up, etc. and 10 additional baseline (feeding)
    double total_training_mins = 0;
// add 1.5 min of cleaning per hour inside
    for (int hours : stalled_hours) {
        total_cleaning_mins += 1.5 * hours;
    }
// add 10 mins per horse is paddocks get picked, except for those in 24/7
    if (paddocks_picked) {
        for (int hours : stalled_hours) {
            if (hours < 24) {
                total_cleaning_mins += 10;
            }
        }
    }
    total_training_mins += 60 * num_in_training;
    double cost = (total_cleaning_mins / 60.0) * 15.0 + (total_training_mins / 60.0) * 25.0; //cleaning wage 15, training wage 25

    return cost;
}
double labor_costs::calc_weekly_labor(int num_horses, const std::vector<int>& stalled_hours,
        int num_in_training, bool paddocks_picked) {
    double daily_cost = calc_daily_labor(num_horses, stalled_hours, num_in_training, paddocks_picked);
    cached_weekly_labor = daily_cost * 7; //weekly cost
    return cached_weekly_labor;
}
