//
// Created by Ellie Sheppard on 9/8/25.
//
#include "feed_costs.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Calculates feed costs for a farm and is able to save such to a csv for future use as well as opening csv file

//reference for grain costs
std::vector<double> grain_costs::grain_prices_ref;
//constructor
grain_costs::grain_costs(std::string n) : name(std::move(n)) {}

//calculate weekly cost per horse
double grain_costs::individual_cost_per_week(const std::vector<double>& grain_prices) const {
    double total = 0;
    for (size_t i = 0; i < grain_amount.size() && i < grain_prices.size(); i++) {
        total += grain_amount[i] * (grain_prices[i] / 50.0 ); //divide by 50, standard size bag in lbs
    }
    return total;
}

//overloaded operator
std::ostream& operator<<(std::ostream& os, const grain_costs& h) {
    os << h.name << ": ";
    for (double i : h.grain_amount) os << i << " ";
    return os;
}

//total weekly cost for all horses
double grain_costs::total_weekly_cost(const std::vector<grain_costs>& horses,
                                   const std::vector<double>& grain_prices) {
    double total = 0;
    for (const auto& h : horses) total += h.individual_cost_per_week(grain_prices);
    return total;
}