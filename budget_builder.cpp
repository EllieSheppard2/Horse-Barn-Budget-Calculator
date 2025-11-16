//
// Created by Ellie Sheppard on 10/3/25.
//

#include "budget_builder.h"

//Combines all related costs for running a farm to give a total weekly budget
// Stores component costs and calculates total cost as an aggregate of all

// adds component costs to be added to total
void budget_builder::add_component_cost(const std::shared_ptr<component_cost> & component) {
    component_costs.push_back(component);
}
// adds component costs together to get total weekly cost to run facility, returns total
double budget_builder::calculate_total_cost(double base_cost) const {
    double total_cost = base_cost;
    for (const auto& component : component_costs) {
        total_cost += component->get_additional_cost();
    }
    return total_cost;
}
