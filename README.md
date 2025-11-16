Horse Barn Budget Calculator

By Ellie Sheppard

The Horse Barn Budget Calculator is a C++ application designed to assist owners and managers in calculating costs associated with
caring for horses in a boarding barn, and therefore determine how much they should charge. It provides an alternative to spreadsheet
based budgeting and is more user friendly in an industry where most are not businesspeople and may be unfamiliar with how to create
a good budget.

It features a feed cost calculator, which users input any feeds they want and cost per 50 lb bag then assign how much of each feed
horses get. It computes cost per horse per week, cost per grain type, and total weekly cost.

Additionally, it will ask questions about labor costs and relevant care and training practices to provide an estimate of weekly 
labor expenses.

The program outputs a feed cost per horse graph, cost per grain type, as well as a spreadsheet-style table with feed amounts, horses,
and costs.


The program is all in C++ with the exception of the cost visualization component (cost_visualizations.py), which is in python. 
If any issues arise with running this, there is a commented terminal command at the top of the file with directions to run manually.
Additionally, the script will print usage instructions if the CSV argument is missing. Note that both these assume the user
already has Python 3 installed on their system.

To run the program, you will need:

A C++ compatible compiler
Python3, pandas and matplotlib

Clone the repository into CLion, and run! Additionally, the graphs can be generated outside the program if a file is saved from previous
runs, see the commented lines at the top of the python file.