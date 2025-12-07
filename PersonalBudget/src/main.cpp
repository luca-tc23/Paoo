#include <iostream>
#include <memory>
#include <sstream>

#include "PersonalBudget.h"
#include "AutoSaveBudget.h"
#include "SharedReport.h"

static std::string serializeBudget(const PersonalBudget& budget)
{
    std::ostringstream oss;
    oss << "Owner: " << budget.getOwnerName() << "\n";
    oss << "Limit lunar: " << budget.getLimit() << " RON\n";
    oss << "Cheltuit: "    << budget.getSpent() << " RON\n";
    oss << "Ramas: "       << (budget.getLimit() - budget.getSpent()) << " RON\n";
    return oss.str();
}

int main()
{
    std::cout << "=== GESTIONARE BUGET PERSONAL ===\n\n";

    // =======================
    // Item 12: Copy all parts
    // =======================
    std::cout << "--- Item 12: Copiere corecta a tuturor partilor ---\n";
    {
        PersonalBudget budget1("Andrei", 1500.0);
        budget1.addExpense("Lapte", 8.5);
        budget1.addExpense("Paine", 4.0);
        budget1.addExpense("Netflix", 40.0);
        budget1.printStatus();

        std::cout << "\n-- Copiere prin copy constructor (budget2 = budget1) --\n";
        PersonalBudget budget2 = budget1;
        budget2.printStatus();

        std::cout << "\n-- Copiere prin assignment (budget3 = budget1) --\n";
        PersonalBudget budget3("AltUser", 2000.0);
        budget3 = budget1;
        budget3.printStatus();
    }

    std::cout << "\n";

    // ==========================
    // Item 13: RAII AutoSaveBudget
    // ==========================
    std::cout << "--- Item 13: RAII - salvare automata buget ---\n";
    {
        PersonalBudget monthlyBudget("Maria", 2500.0);
        monthlyBudget.addExpense("Chirie", 1200.0);
        monthlyBudget.addExpense("Abonament telefon", 50.0);
        monthlyBudget.addExpense("Cumparaturi supermarket", 300.0);
        monthlyBudget.printStatus();

        AutoSaveBudget autoSave("buget_maria.txt",
                                serializeBudget(monthlyBudget));

        monthlyBudget.addExpense("Cinema", 60.0);
        monthlyBudget.printStatus();

        autoSave.updateData(serializeBudget(monthlyBudget));

        std::cout << "La iesirea din acest bloc, 'buget_maria.txt' se salveaza automat...\n";
    }

    std::cout << "\n";

    // ===========================================
    // Item 14: copying behavior + shared_ptr RAII
    // ===========================================
    std::cout << "--- Item 14: Raport financiar partajat (reference counting) ---\n";
    {
        auto rep = std::make_shared<Report>(
            "Raport buget familie",
            "Titlu: Cheltuieli luna curenta\n\n"
        );

        std::cout << "\n-- Parinte1 deschide raportul --\n";
        SharedReport parent1(rep);
        parent1.printInfo("Parinte1");
        parent1.edit("Sectiunea 1: Cheltuieli esentiale (chirie, utilitati).");

        std::cout << "\n-- Parinte2 deschide acelasi raport --\n";
        SharedReport parent2 = parent1;  // copy -> use_count creste
        parent2.printInfo("Parinte2");
        parent2.edit("Sectiunea 2: Cheltuieli optionale (distractii, iesiri).");

        std::cout << "\n-- Copilul verifica raportul temporar --\n";
        {
            SharedReport child = parent2;
            child.printInfo("Copil");
            child.edit("Sectiunea 3: Economii pentru vacanta.");

            child.view();
        } // child iese din scope -> use_count scade

        std::cout << "\n-- Dupa ce copilul a iesit --\n";
        parent1.printInfo("Parinte1");
        parent2.printInfo("Parinte2");

        std::cout << "\n-- Parinte1 vizualizeaza raportul final --\n";
        parent1.view();
    }

    std::cout << "\n=== APLICATIE BUGET INCHISA ===\n";
    return 0;
}