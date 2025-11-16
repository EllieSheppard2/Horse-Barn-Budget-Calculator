Horse Barn Budget Calculator

By Ellie Sheppard

Welcome to the horse barn budget calculator! This is meant to be an alternative to using a spreadsheet in order to 
calculate costs involved in running a horse barn. For some backstory, the UVM horse barn is currently losing a ton
of money! I am in charge of ordering feed, so I thought calculating costs of feed might be a good starting point in
a budget calculator.

This program prompts the user for types of feed, then asks for how much each bag costs. Once the user has inputted all
types of feed, it prompts for each horse and asks how much of each feed they get. After the user is done, it displays
the horses as rows with how much of each feed they get, columns of feed, and price per bag, price per horse per week, 
and total weekly cost assuming all bags are the standard 50 lbs.

Module 1 Concepts used:

Class: grain_costs 
    fields: name and grain_amount
    methods: individual_cost_per_week(), total_weekly_cost()
Overloaded Operator: printing grain_costs object

Future expansions on this project might be estimated labor costs (prompting users for info on how horses are kept,
such as stalls or pastures) as well as costs to maintain figuring in size and age of facility and number of animals,
and calculations on how much to charge for services to meet an expected salary.

I feel that this project should earn full points, as I have spent a considerable amount of time and effort on it
ensuring that the input validation is robust, it calculates and displays costs accurately, and the program is of
adequate complexity. Additionally, I think the concept is well thought out and will be a good starting point for future
modules with a real-world application that I can personally use.

Module 2 Concepts used:
Feed and labor costs are child classes of component costs. They are also components of
budget builder.

Module 3 Concepts used:
I chose to use python for visualizing costs as it has packages that make it much much better for that than C++.
The cost_visualizations file takes the csv saved from the user input and contains two functions to graph 
invididual monthly costs and monthly costs per grain type. It then can be called by the main cpp file and will output
graphs at the end of the program.

Future expansions on this project would be adding labor costs to the saved csv file and creating visualizations for those as well.
Additionally, it needs input validation for labor. I think the last cost category it is missing for budget calculations would be 
facility maintenence costs, and possibly non- physical labor employee costs if applicable. 

I think this project should earn full points as it now actually does save to a csv, and it uses another language effectively to do something
C++ is really bad at doing.

Known Problems/Bugs:

No input validation for labor. You can break it there.
