#pragma once

#include <memory>
#include <string>
#include <iostream>

// Raport financiar simplu partajat între mai mulți utilizatori
class Report
{
public:
    Report(const std::string& title, const std::string& content);
    ~Report();

    void addSection(const std::string& section);
    void display() const;

    std::string getTitle() const { return title; }

private:
    std::string title;
    std::string content;
};

// Ambalaj RAII + copying behavior clar: shared_ptr pentru ownership partajat
class SharedReport
{
public:
    explicit SharedReport(std::shared_ptr<Report> report);

    // Copy ctor + operator= generate implicit sunt OK (shared_ptr face ref counting)

    void edit(const std::string& section);
    void view() const;
    void printInfo(const std::string& userName) const;

private:
    std::shared_ptr<Report> report;
};