#include "PersonalBudget.h"
#include <iostream>

PersonalBudget::PersonalBudget(const std::string& ownerName,
                               double monthlyLimit)
    : BudgetBase(ownerName),
      shoppingList("Lista de cumparaturi a lui " + ownerName),
      monthlyLimit(monthlyLimit)
{
    std::cout << "[PersonalBudget ctor] owner='" << ownerName
              << "', limit=" << monthlyLimit << " RON\n";
}

// Copy constructor
PersonalBudget::PersonalBudget(const PersonalBudget& other)
    : BudgetBase(other),               // copiem partea de BAZĂ
      shoppingList(other.shoppingList),// copiem lista de cumpărături
      monthlyLimit(other.monthlyLimit) // copiem bugetul
{
    std::cout << "[PersonalBudget copy ctor] owner='" << ownerName
              << "', limit=" << monthlyLimit << " RON\n";
}

// Copy assignment
PersonalBudget& PersonalBudget::operator=(const PersonalBudget& other)
{
    std::cout << "[PersonalBudget operator=]\n";

    if (this == &other) return *this;

    // 1) copiem partea de bază
    BudgetBase::operator=(other);

    // 2) copiem membrii proprii
    shoppingList  = other.shoppingList;
    monthlyLimit  = other.monthlyLimit;

    return *this;
}

void PersonalBudget::addExpense(const std::string& itemName, double price)
{
    shoppingList.addItem(itemName, price);
}

void PersonalBudget::printStatus() const
{
    std::cout << "\n=== Bugetul lui " << ownerName << " ===\n";
    shoppingList.print();
    std::cout << "Limită lunară: " << monthlyLimit << " RON\n";
    std::cout << "Cheltuit:      " << shoppingList.getTotal() << " RON\n";
    std::cout << "Rămas:         " << (monthlyLimit - shoppingList.getTotal())
              << " RON\n";
    std::cout << "==============================\n\n";
}