/**
 * @file Medium.cpp
 * @author David Todorov
 * @brief Class Definition of Medium
 */
#include "../Header Files/Medium.h"
using namespace std;

//* Constructor which takes 4 arguments
Medium::Medium(string abbreviation, string author, string title, int yearOfPubl){
    this->abbreviation = abbreviation;
    this->author = author;
    this->title= title;
    this->yearOfPubl = yearOfPubl;
}

//* Implementation of getters and setters
string Medium::getAbbreviation(){
    return this->abbreviation;
}

void Medium::setAbbreviation(string abbreviation){
    this->abbreviation = abbreviation;
}

string Medium::getAuthor(){
    return this->author;
}

void Medium::setAuthor(string author){
    this->author = author;
}

string Medium::getTitle(){
    return this->title;
}

void Medium::setTitle(string title){
    this->title = title;
}

int Medium::getYearOfPublication(){
    return this->yearOfPubl;
}

void Medium::setYearOfPublication(int yearOfPublication){
    this->yearOfPubl = yearOfPubl;
}

//* Base implementation of toString() method which can be overridden 
string Medium::toString() const{
    return "[" + this->abbreviation + "] " + this->author + ": " + this->title;
}