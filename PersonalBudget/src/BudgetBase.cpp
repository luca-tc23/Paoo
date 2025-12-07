#include "BudgetBase.h"

BudgetBase::BudgetBase(const std::string& ownerName)
    : ownerName(ownerName)
{
    std::cout << "[BudgetBase ctor] owner='" << ownerName << "'\n";
}

BudgetBase::BudgetBase(const BudgetBase& other)
    : ownerName(other.ownerName)
{
    std::cout << "[BudgetBase copy ctor] from '" << other.ownerName
              << "' to '" << ownerName << "'\n";
}

BudgetBase& BudgetBase::operator=(const BudgetBase& other)
{
    std::cout << "[BudgetBase operator=] '" << other.ownerName
              << "' -> '" << ownerName << "'\n";

    if (this == &other) return *this;

    ownerName = other.ownerName;
    return *this;
}