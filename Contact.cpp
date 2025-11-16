#include "Contact.hpp"
#include <iostream>
#include <cstring>

Contact::Contact(const char* n, const char* p) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    phone = new char[strlen(p) + 1];
    strcpy(phone, p);
}

Contact::~Contact() {
    delete[] name;
    delete[] phone;
}

Contact::Contact(const Contact& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    phone = new char[strlen(other.phone) + 1];
    strcpy(phone, other.phone);
}

Contact& Contact::operator=(const Contact& other) {
    if (this == &other)
        return *this;

    delete[] name;
    delete[] phone;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    phone = new char[strlen(other.phone) + 1];
    strcpy(phone, other.phone);

    return *this;
}

void Contact::print() const {
    std::cout << "Name: " << name << ", Phone: " << phone << std::endl;
}