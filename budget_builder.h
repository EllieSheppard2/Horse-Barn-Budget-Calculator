//
// Created by Ellie Sheppard on 10/3/25.
//

#ifndef BUDGET_BUILDER_H
#define BUDGET_BUILDER_H
#include "component_cost.h"
#include <memory>
#include <vector>

//Combines all related costs for running a farm to give a total weekly budget
// Stores component costs and calculates total cost as an aggregate of all


class budget_builder {
private:
    std::vector<std::shared_ptr<component_cost>> component_costs;
public:
    // adds a component cost to the total
    void add_component_cost(const std::shared_ptr<component_cost> & component);
    // calculates total cost out of the components
    double calculate_total_cost(double base_cost) const;
};

#endif //BUDGET_BUILDER_H
