cmake_minimum_required(VERSION 3.10)
project("CS2300 Open-Ended" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main_1
        main.cpp
        feed_costs.cpp
        feed_costs.h
        budget_builder.cpp
        budget_builder.h
        labor_costs.cpp
        labor_costs.h
        component_cost.h
        cost_visualizations.py
)
