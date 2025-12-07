#include "SharedReport.h"

// ---- Report ----

Report::Report(const std::string& title, const std::string& content)
    : title(title),
      content(content)
{
    std::cout << "[Report ctor] '" << title << "'\n";
}

Report::~Report()
{
    std::cout << "[Report dtor] '" << title << "'\n";
}

void Report::addSection(const std::string& section)
{
    content += section + "\n";
}

void Report::display() const
{
    std::cout << "\n=== Report: " << title << " ===\n";
    std::cout << content;
    std::cout << "=== End Report ===\n\n";
}

// ---- SharedReport ----

SharedReport::SharedReport(std::shared_ptr<Report> report)
    : report(std::move(report))
{
    std::cout << "[SharedReport ctor] use_count=" << this->report.use_count()
              << "\n";
}

void SharedReport::edit(const std::string& section)
{
    if (report)
    {
        report->addSection(section);
    }
}

void SharedReport::view() const
{
    if (report)
    {
        report->display();
    }
}

void SharedReport::printInfo(const std::string& userName) const
{
    std::cout << "User '" << userName << "' - report '"
              << report->getTitle() << "' - use_count="
              << report.use_count() << "\n";
}