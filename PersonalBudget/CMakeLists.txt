cmake_minimum_required(VERSION 3.10)

project(PersonalBudget LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(personal_budget
    src/main.cpp
    src/BudgetBase.cpp
    src/ShoppingList.cpp
    src/PersonalBudget.cpp
    src/AutoSaveBudget.cpp
    src/SharedReport.cpp
)

target_include_directories(personal_budget PRIVATE ${CMAKE_SOURCE_DIR}/src)