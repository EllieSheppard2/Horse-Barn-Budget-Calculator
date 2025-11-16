//
// Created by Ellie Sheppard on 10/3/25.
//

#ifndef LABOR_COSTS_H
#define LABOR_COSTS_H
#include <vector>
#include "component_cost.h"
// Models weekly labor costs for farm
// Adjusts for hours horses spend in stall, whether paddocks are picked or not, and how many horses are in training
// Also provides weekly labor cost for budget builder class (total operating costs)
class labor_costs : public component_cost {

public:
    labor_costs() = default;
    //labor costs per day and week (same but x7); take into account hours picking (cleaning per day),
    //and training at different rates ($15 and $25)
    double calc_daily_labor (int num_horses, const std::vector<int>& stalled_hours,
        int num_in_training, bool paddocks_picked);
    double calc_weekly_labor (int num_horses, const std::vector<int>& stalled_hours,
        int num_in_training, bool paddocks_picked);
    // getter for budget builder
    double get_additional_cost() const override {
        return cached_weekly_labor;
    }
    void set_weekly_labor(double val) {cached_weekly_labor = val;}
private:
    //stores most recent weekly labor calculation
    double cached_weekly_labor = 0;
};

#endif //LABOR_COSTS_H
