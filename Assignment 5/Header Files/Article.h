/**
 * @file Article.h
 * @author David Todorov
 * @brief Header file for Article class. derived from Medium
 */
#ifndef ARTICLE_H_
#define ARTICLE_H_

#include "Medium.h"
#include <string>
using namespace std;

class Article : public Medium
{
    /**
     * @brief Private attributes
     * 
     */
private:
    string magazineName;
    int magazineNumber;
    int pageNumber;

public:
    Article( string abbreviation, string author, string title, int yearOfPubl,string magazineName, int magazineNumber, int pageNumber);
    virtual string toString() const;
};

#endif