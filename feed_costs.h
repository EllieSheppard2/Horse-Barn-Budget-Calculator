//
// Created by Ellie Sheppard on 9/8/25.
//
#ifndef FEED_COSTS_H
#define FEED_COSTS_H

#include <string>
#include <vector>
#include <iostream>
#include "component_cost.h"

// Calculates feed costs for a farm and is able to save such to a csv for future use
class grain_costs : public component_cost {
public:
    std::string name;
    std::vector<double> grain_amount;

//constructor
    grain_costs(std::string n = "");

// calculates invidual cost per week (per horse)
    double individual_cost_per_week(const std::vector<double>& grain_prices) const;

// overloaded operator for printing with a really fun keyword
    friend std::ostream& operator<<(std::ostream& os, const grain_costs& h);

// calculates total weekly cost for all horses
    static double total_weekly_cost(const std::vector<grain_costs>& horses, const std::vector<double>& grain_prices);
    // reference to grain prices
    double get_additional_cost() const override {
        return individual_cost_per_week(grain_prices_ref);
    }
    static std::vector<double> grain_prices_ref;
};


// saving and loading data to a csv (would like to expand on project to make changes to csv and further budget calculations)
void save_to_csv(const std::string& filename,
                 const std::vector<std::string>& grain_types,
                 const std::vector<double>& grain_prices,
                 const std::vector<grain_costs>& horses);

std::vector<grain_costs> grain_from_csv(const std::string& filename);

#endif //FEED_COSTS_H
