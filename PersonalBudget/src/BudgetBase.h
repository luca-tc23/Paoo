#pragma once

#include <string>
#include <iostream>

// Clasă de bază pentru orice tip de buget (ține numele utilizatorului)
class BudgetBase
{
public:
    explicit BudgetBase(const std::string& ownerName);

    BudgetBase(const BudgetBase& other);
    BudgetBase& operator=(const BudgetBase& other);

    virtual ~BudgetBase() = default;

    const std::string& getOwnerName() const { return ownerName; }

protected:
    std::string ownerName; // protejat, pentru clasele derivate
};