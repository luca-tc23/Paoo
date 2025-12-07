#pragma once

#include "BudgetBase.h"
#include "ShoppingList.h"
#include <string>

// Item 12 + moștenire:
// PersonalBudget DERIVĂ din BudgetBase și conține ShoppingList ca membru.

class PersonalBudget : public BudgetBase
{
public:
    explicit PersonalBudget(const std::string& ownerName,
                            double monthlyLimit);

    PersonalBudget(const PersonalBudget& other);
    PersonalBudget& operator=(const PersonalBudget& other);

    void addExpense(const std::string& itemName, double price);
    void printStatus() const;

    double getLimit() const { return monthlyLimit; }
    double getSpent() const { return shoppingList.getTotal(); }

private:
    ShoppingList shoppingList;  // obiect-membru (lista de cumpărături)
    double       monthlyLimit;  // buget lunar
};