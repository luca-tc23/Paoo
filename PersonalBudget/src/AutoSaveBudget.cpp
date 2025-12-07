#include "AutoSaveBudget.h"
#include <iostream>
#include <fstream>

AutoSaveBudget::AutoSaveBudget(const std::string& filename,
                               const std::string& serializedBudget)
    : filename(filename),
      data(serializedBudget)
{
    std::cout << "[AutoSaveBudget ctor] Pregatit pentru salvare: '"
              << filename << "'\n";
}

AutoSaveBudget::~AutoSaveBudget()
{
    std::cout << "[AutoSaveBudget dtor] Salvez automat '" << filename << "'...\n";

    std::ofstream file(filename);
    if (file.is_open())
    {
        file << data;
        file.close();
        std::cout << "[AutoSaveBudget] ✓ Salvat cu succes!\n";
    }
    else
    {
        std::cout << "[AutoSaveBudget] ✗ Eroare la salvare!\n";
    }
}

void AutoSaveBudget::updateData(const std::string& newSerializedBudget)
{
    data = newSerializedBudget;
    std::cout << "[AutoSaveBudget::updateData] Date actualizate pentru '"
              << filename << "'\n";
}