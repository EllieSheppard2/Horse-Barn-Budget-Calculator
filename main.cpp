//
// Created by Ellie Sheppard on 9/14/25.
//
#include <iostream>
#include <vector>
#include <string>
#include "feed_costs.h"
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <sstream>


#include "budget_builder.h"
#include "labor_costs.h"

using namespace std;

//save to csv (self explanatory)
void save_to_csv(const std::string& filename,
                 const std::vector<std::string>& grain_types,
                 const std::vector<double>& grain_prices,
                 const std::vector<grain_costs>& horses) {
    std::ofstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Error opening file to save to: " << filename << std::endl;
        return;
    }
    file << "#elliespassword\n"; //signature to verify for re-opening
    file << "Grain type";
    for (const auto& g : grain_types) file << ',' << g;
    file << '\n';

    file << "Price";
    for (double p : grain_prices) file << ',' << p;
    file << '\n';

    for (const auto& h : horses) {
        file << h.name;
        for (double amount : h.grain_amount) file << ',' << amount;
        file << '\n';
    }
}
//loading in from csv
std::vector<grain_costs> grain_from_csv(const std::string& filename) {
    std::vector<grain_costs> horses;
    std::ifstream file(filename);
    std::string line;

    if(!file.is_open()) {
        cerr << "Error opening file " << filename << std::endl;
        return{};
    }
    if (!getline(file, line)) {
        cerr << "Error, file is empty";
        return {};
    }
    const string signature = "elliespassword";
    if(line != signature) {
        cerr<<"Error, file was not saved from this program.";
        return{};
    }
    std::getline(file, line); // skip grain type row
    std::getline(file, line); // skip price row

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        grain_costs h;

        std::getline(ss, h.name, ',');
        while(std::getline(ss, cell, ',')) {
            if(!cell.empty())
                h.grain_amount.push_back(std::stod(cell));
            else
                h.grain_amount.push_back(0);
        }

        horses.push_back(h);
    }

    return horses;
}


int main() {

    vector<string> grain_types;
    vector<double> grain_prices;
    vector<grain_costs> horses;

    cout << "Enter the name of the CSV file saved from last run of this program, press enter to skip ";
    string filename;
    getline(cin, filename); //if enter

    if (!filename.empty()) {
        horses = grain_from_csv(filename);
        if(horses.empty()) {
            cout << "Continuing without loading CSV data";
        }
        else {
            cout << "Loaded data from CSV. Continue with program to add additional data";
        }
    }
    else {
        cout << "No file entered, starting new one.\n";
    }


    //FEED COSTS and table
    //first, entering in grain types and prices
    cout << "Enter a grain type (enter 0 to finish entering types): \n";
    while(true) {
        string grain;
        cout<< "Name: ";
        getline(cin, grain);//fixed to read whole line (ex "TC Senior")
        if(grain == "0") break;
        grain_types.push_back(grain);
        double price;
        while (true) { //validate that it is a whole number or 1 decimal point
            string input;
            cout << "Price per bag for " << grain << ": ";
            getline(cin, input);

            bool valid = !input.empty() &&
                         count(input.begin(), input.end(), '.') <= 1 && all_of(input.begin(), input.end(), [](char c) { return isdigit(c) || c == '.';});
            if (valid) {
                grain_prices.push_back(stod(input));
                break;
            }
            else {
                cout << "Nope! Not a number :( Enter a number and only a number \n";
            }
        }
    }
    //prompting for horses, then grain amounts per type
    cout << "Enter horses (enter 0 to finish entering types): \n";

    while(true) {
        string horse;
        cout << "Name: ";
        getline(cin, horse);
        if(horse == "0") break;
        grain_costs h(horse);
        h.grain_amount.resize(grain_types.size());
        for (size_t i = 0; i < grain_types.size(); i++) {
            double amount;
            while (true) {
                string input;
                cout <<"Enter weekly amount of " << grain_types[i] << " in pounds for " << horse << " or 0 if none: ";
                getline(cin, input);

                bool valid = !input.empty() &&//validate that it is a whole number or 1 decimal point
                         count(input.begin(), input.end(), '.') <= 1 && all_of(input.begin(), input.end(), [](char c) { return isdigit(c) || c == '.';});
                if (valid) {
                    h.grain_amount[i] = stod(input);
                    break;
                }
                else {
                    cout << "Nope! Not a number :( Enter a number \n";
                }
            }
        }
        horses.push_back(h);
    }
    //printing table
    //header
    cout << setw(15) << "Horse";
    for (const auto&g : grain_types)
        cout << setw(10) << g;
    cout << setw(20) << "Cost per week";
    cout << "\n";
    //prices
    cout << setw(15) << "Price/Bag";
    for (double p : grain_prices)
        cout << setw(10) << p;
    cout << "\n";
    //horses
    for (const auto& h : horses) {
        cout << setw(15) << h.name;
        for (double amount : h.grain_amount)
            cout << setw(10) << amount;
        cout << setw(20) << h.individual_cost_per_week(grain_prices);
        cout << "\n";
    }
    //total cost
    double total = grain_costs::total_weekly_cost(horses, grain_prices);
    cout << setw(15) << "Total weekly cost: $";
    cout << total << "\n";

    //initialize budget
    budget_builder budget;
    //add to budget builder (loop through per horse)
    grain_costs::grain_prices_ref = grain_prices;
    for (auto& h : horses) {
        budget.add_component_cost(std::make_shared<grain_costs>(h));
    }


    //LABOR COSTS (print weekly)
    int num_horses = horses.size();
// loop through horses, ask how many hours each are stalled. store it in stalled hours vector
    vector<int> stalled_hours(num_horses);
    for (int i = 0; i < num_horses; i++) {
        cout << "How many hours per day is " << horses[i].name << " stalled? ";
        cin >> stalled_hours[i];
    }
    int num_in_training;
    cout << "How many horses are in full training? ";
    cin >> num_in_training;

    char choice;
    bool paddocks_picked = false;
    cout << "Are paddocks picked daily? Press y if yes ";
    cin >> paddocks_picked;
    if (choice == 'y' || choice == 'Y') {
        paddocks_picked = true;
    }
// calculating weekly labor costs
    shared_ptr<labor_costs> labor = make_shared<labor_costs>();
    double weekly_labor = labor->calc_weekly_labor(num_horses, stalled_hours, num_in_training, paddocks_picked);
    labor->set_weekly_labor(weekly_labor);

    cout << "Weekly labor costs is $ " << weekly_labor << " per week" << endl;

    budget.add_component_cost(labor);

    //total budget calculations
    double total_budget = budget.calculate_total_cost(0.0);
    cout << "Total weekly expenses are $" << total_budget << endl;

    save_to_csv("feed_costs.csv", grain_types, grain_prices, horses);//could change this to prompt user for name?

    //running python file to graph
    int graphing = system("python3 cost_visualizations.py feed_costs.csv");
    if (graphing != 0) {
        cerr << "Error creating graphs";
    }

    return 0;
}