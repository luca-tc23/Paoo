#include "ShoppingList.h"

ShoppingList::ShoppingList()
    : title("Lista fara nume"), total(0.0)
{
    std::cout << "[ShoppingList default ctor] title='" << title << "'\n";
}

ShoppingList::ShoppingList(const std::string& title)
    : title(title), total(0.0)
{
    std::cout << "[ShoppingList ctor] title='" << title << "'\n";
}

ShoppingList::~ShoppingList()
{
    std::cout << "[ShoppingList dtor] title='" << title
              << "', total=" << total << "\n";
}

ShoppingList::ShoppingList(const ShoppingList& other)
    : title(other.title), items(other.items), total(other.total)
{
    std::cout << "[ShoppingList copy ctor] title='" << title
              << "', total=" << total << "\n";
}

ShoppingList& ShoppingList::operator=(const ShoppingList& other)
{
    std::cout << "[ShoppingList operator=]\n";
    if (this == &other) return *this;

    title = other.title;
    items = other.items;
    total = other.total;
    return *this;
}

void ShoppingList::addItem(const std::string& name, double price)
{
    items.push_back({ name, price });
    total += price;

    std::cout << "[ShoppingList::addItem] '" << name
              << "' - " << price << " RON (total=" << total << ")\n";
}

void ShoppingList::print() const
{
    std::cout << "\n--- " << title << " ---\n";
    for (const auto& it : items)
    {
        std::cout << "  - " << it.name << " : " << it.price << " RON\n";
    }
    std::cout << "Total: " << total << " RON\n";
    std::cout << "-------------------------\n\n";
}