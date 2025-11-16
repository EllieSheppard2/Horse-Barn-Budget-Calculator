//
// Created by Ellie Sheppard on 10/3/25.
//

#ifndef COMPONENT_COST_H
#define COMPONENT_COST_H

// interface for type of cost to be included in the budget builder. all cost component classes
// inherit from this

class component_cost {
public:
    virtual ~component_cost() = default;
    virtual double get_additional_cost() const = 0;
};

#endif //COMPONENT_COST_H