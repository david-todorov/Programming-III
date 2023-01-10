/**
 * @file Article.cpp
 * @author David Todorov
 * @brief Implementation of Article class derived from Medium
 */
#include "../Header Files/Article.h"
#include <string>
#include "iostream"
using namespace std;

Article :: Article(string abbreviation, string author, string title, int yearOfPubl, string magazineName, int magazineNumber, int pageNumber) : Medium(abbreviation, author, title, yearOfPubl)
{
    this->magazineName = magazineName;
    this->magazineNumber = magazineNumber;
    this->pageNumber = pageNumber;
}

/**
* @brief Overriding a toString() method but still using the functionality of the base class
 * 
 * @return formated string representing an Article 
 */
string Article :: toString() const {
    return Medium::toString() + ". " + this->magazineName + ", " + to_string(this->magazineNumber) + ", " + to_string(this->yearOfPubl) + ", " + to_string(this->pageNumber);
    
}