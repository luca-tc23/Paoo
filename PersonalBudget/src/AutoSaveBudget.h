#pragma once

#include <string>

// Item 13: RAII - salvează automat bugetul la distrugere
// Item 14: Copiere interzisă (pentru siguranța resursei)

class AutoSaveBudget
{
public:
    AutoSaveBudget(const std::string& filename,
                   const std::string& serializedBudget);
    ~AutoSaveBudget();

    AutoSaveBudget(const AutoSaveBudget&)            = delete;
    AutoSaveBudget& operator=(const AutoSaveBudget&) = delete;

    void updateData(const std::string& newSerializedBudget);
    std::string getFilename() const { return filename; }

private:
    std::string filename;
    std::string data;
};