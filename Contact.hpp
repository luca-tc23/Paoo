#pragma once
#include <iostream>

class Contact
{
private:
    char* name;
    char* phone;

public:
    Contact(const char* n = "", const char* p = "");
    Contact(const Contact& other);
    Contact& operator=(const Contact& other);
    ~Contact();

    const char* getName() const { return name; }
    const char* getPhone() const { return phone; }

    void print() const;
};