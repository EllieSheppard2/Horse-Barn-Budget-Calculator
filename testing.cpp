//
// Created by Ellie Sheppard on 10/5/25.
//

#include "testing.h"
#include <vector>
#include "feed_costs.h"
#include <iostream>
#include "labor_costs.h"
using namespace std;

int main() {
    //testing for FEED cost functions

    //create horse Mango, with no grain inputs
    bool passed = true;
    cout << "Start of feed costs testing" << endl;
    grain_costs g("Mango");
    if(g.name == "Mango") {
        cout << "PASSED constructor setting name test" << endl;
    }
    else {
        cout <<"FAILED constructor setting name test" << endl;
        passed = false;
    }
    if(g.grain_amount.empty()) {
        cout << "PASSED initializes empty grain amount test" << endl;
    }
    else {
        cout << "FAILED intizializes empty grain amount test" << endl;
        passed = false;
    }
    g.grain_amount = {5.0 , 5.5};
    vector<double> prices = {32.0, 25.0};
    //testing individual cost per week function
    double cost = g.individual_cost_per_week(prices);
    if (cost == 5.95) {
        cout << "PASSED individual cost per week calculation" << endl;
    }
    else {
        cout << "FAILED individual cost per week calculation" << endl;
        passed = false;
    }
    //testing total cost per week function
    grain_costs g1("Ruby");
    g1.grain_amount = {5.0, 5.5};
    vector<grain_costs> horses = {g, g1};
    double total = grain_costs::total_weekly_cost(horses, prices);
    if (total == 11.90) {
        cout << "PASSED total cost per week calculation" << endl;
    }
    else {
        cout << "FAILED total cost per week calculation" << endl;
        passed = false;
    }
    //testing get additional feed costs function
    grain_costs::grain_prices_ref = prices;
    double add_cost = g.get_additional_cost();
    if (add_cost == 5.95) {
        cout << "PASSED get additional cost for Mango" << endl;
    }
    else {
        cout << "FAILED get additional cost for Mango" << endl;
        passed = false;
    }
    if (passed) {
        cout << "\n ALL FEED COST TESTS PASSED\n" << endl;
    }
    else {
        cout << "\n FAILED one or more feed cost tests\n" << endl;
    }

    //testing for LABOR costs functions

    labor_costs lc;

// case 1: 1 horse, stalled 6 hrs, no training, no picking
    vector<int> stalled_hours = {6};
    double daily_labor = lc.calc_daily_labor(1, stalled_hours, 0 , false);
    if (daily_labor == 12.25) {
        cout << "PASSED daily labor calculation test" << endl;
    }
    else {
        cout << "FAILED daily labor calculation test" << endl;
        passed = false;
    }
    double weekly_labor = lc.calc_weekly_labor(1, stalled_hours, 0, false);
    if (weekly_labor == 85.75) {
        cout << "PASSED weekly labor calculation test" << endl;
    }
    else {
        cout << "FAILED weekly labor calculation test" << endl;
        passed = false;
    }
// case 2: 2 horses, 4/8 hours talled, 1 in training, paddocks picked
    vector<int> stalled_hours1 = {4, 8};
    double daily_labor1 = lc.calc_daily_labor(2, stalled_hours1, 1, true);
    if (daily_labor1 == 47.0) {
        cout << "PASSED daily labor calculation test 2" << endl;
    }
    else {
        cout << "FAILED daily labor calculation test 2" << endl;
        passed = false;
    }
    double weekly_labor1 = lc.calc_weekly_labor(2, stalled_hours1, 1, true);
    if (weekly_labor1 == 329.0) {
        cout << "PASSED weekly labor calculation test 2" << endl;
    }
    else {
        cout << "FAILED weekly labor calculation test 2" << endl;
        passed = false;
    }

    //case 3: 3 horses, all stalled 24 hrs, 2 in training, paddocks picked
    vector<int> stalled_hours2 = {24, 24, 24};
    double daily_labor2 = lc.calc_daily_labor(3, stalled_hours2, 2, true);
    if (daily_labor2 == 92.0) {
        cout << "PASSED daily labor calculation test 3" << endl;
    }
    else {
        cout << "FAILED daily labor calculation test 3" << endl;
        passed = false;
    }
    double weekly_labor2 = lc.calc_weekly_labor(3, stalled_hours2, 2, true);
    if (weekly_labor2 == 644) {
        cout << "PASSED weekly labor calculation test 3" << endl;
    }
    else {
        cout << "FAILED weekly labor calculation test 3" << endl;
        passed = false;
    }
    if (passed) {
        cout << "\n ALL LABOR COST TESTS PASSED" << endl;
    }
    else {
        cout << "\n FAILED one or more labor cost tests" << endl;
    }
}

//testing that i could add: budget builder testing