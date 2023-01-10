/**
 * @file Book.h
 * @author David Todorov
 * @brief Header file for class Book, derived from class Medium
 */
#ifndef BOOK_H_
#define BOOK_H_

#include "Medium.h"
#include <string>
using namespace std;

class Book : public Medium
{
        //* Additional private attribute publisher
private:
        string publisher;

public:
        Book(string abbreviation, string author, string title, int yearOfPubl, string publisher);
        //* toString() method which still can be overriden from derived class
        virtual string toString() const;
};
#endif