/**
 * @file Book.cpp
 * @author David Todorov
 * @brief Implementation of Book class derived from Medium
 */
#include "../Header Files/Book.h"
#include <string>
using namespace std;

Book::Book( string abbreviation, string author, string title, int yearOfPubl,string publisher) : Medium(abbreviation, author, title, yearOfPubl)
{
    this->publisher = publisher;
}

/**
 * @brief Overriding a toString() method but still using the functionality of the base class
 * 
 * @return formated string representing a Book 
 */
string Book ::toString() const
{
    return Medium::toString() + ". " + this->publisher + ", " + to_string(this->yearOfPubl);
}
