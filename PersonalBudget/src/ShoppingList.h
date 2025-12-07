#pragma once

#include <iostream>
#include <vector>
#include <string>

// Listă simplă de cumpărături – gestionează dinamic produsele și costurile
class ShoppingList
{
public:
    ShoppingList();
    explicit ShoppingList(const std::string& title);
    ~ShoppingList();

    ShoppingList(const ShoppingList& other);
    ShoppingList& operator=(const ShoppingList& other);

    void addItem(const std::string& name, double price);
    void print() const;

    double getTotal() const { return total; }
    const std::string& getTitle() const { return title; }

private:
    struct Item
    {
        std::string name;
        double price;
    };

    std::string        title;
    std::vector<Item>  items;
    double             total;
};