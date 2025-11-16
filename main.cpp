#include "Contact.hpp"
#include <iostream>

int main() 
{
    std::cout << "\n=== Practical Need for Item 12 (Deep Copy) ===\n";

    Contact Original("Ana", "0712345678");
    Contact Backup = Original;

    Backup = Contact("Ana_MODIFIED", "999999999");

    std::cout << "Original should stay unchanged:\n";
    Original.print();

    std::cout << "Backup modified independently:\n";
    Backup.print();

    std::cout << "If deep copy DID NOT exist, modifying Backup would corrupt Original.\n";



    std::cout << "\n=== Practical Need for Item 11 (Self-Assignment Protection) ===\n";

    Contact C("Maria", "0750000000");
    Contact& SameRef = C;

    std::cout << "Before C = SameRef (self-assign):\n";
    C.print();

    C = SameRef;

    std::cout << "After C = SameRef (object should remain valid):\n";
    C.print();

    std::cout << "Without Item 11, this could free its own memory before copying it.\n";



    std::cout << "\n=== Practical Need for Item 10 (operator= returns *this) ===\n";

    Contact X("X", "111");
    Contact Y("Y", "222");
    Contact Z("Z", "333");

    X = Y = Z;

    std::cout << "After X = Y = Z, X becomes:\n";
    X.print();

    std::cout << "Without returning *this, chaining would NOT work.\n";


    return 0;
}