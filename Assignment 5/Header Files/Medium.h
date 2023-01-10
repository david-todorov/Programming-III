/**
 * @file Medium.h
 * @author David Todorov
 * @brief A header file for Medium class
 */
#ifndef MEDIUM_H_
#define MEDIUM_H_

#include <string>
using namespace std;

class Medium
{
    /**
     * @brief Protected atributes, so they can be accessed from derived classes
     * 
     */
protected:
        string abbreviation; 
        string author; 
        string title;
        int yearOfPubl;

public:

    Medium(string abbreviation, string author,string title, int yearOfPubl);

    //* Getters and Setters for the private attributes
    string getAbbreviation();
    void setAbbreviation(string abbreviation);

    string getAuthor();
    void setAuthor(string author);

    string getTitle();
    void setTitle(string title);

    int getYearOfPublication();
    void setYearOfPublication(int yearOfPubl);

    //* Virtual method toString() because every object later needs to act accordingly
    virtual string toString() const;
};

#endif
