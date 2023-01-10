/**
 * @file mystring.cpp
 * @author David Todorov
 * @brief Definition file for mystring.h
 */
#include "mystring.h"
#include <iostream>
#include <cstring>
using namespace stringexercise;

/**
 * @brief Initial size for a string with empty constructor
 * 
 */
const int INIT_SIZE = 2;

/**
 * @brief Empty Construct, no parameters, the INIT_SIZE is used here
 * 
 */
mystring::mystring()
{
    this->sequence = new char[INIT_SIZE];
    this->occupied = 0;
    this->capacity = INIT_SIZE;
}

/**
 * @brief Construct with C String as parameter
 * 
 * @param str 
 */
mystring::mystring(const char str[])
{
    int strLength = strlen(str); //Getting the length of C String
    this->sequence = new char[strLength]; 

    this->insertSequanceAt(0, strLength, str); //Inserting multiple elements at given start with specific length

    this->occupied = strLength;
    this->capacity = 0;
}

/**
 * @brief Constructor with std:;string paramter
 */
mystring::mystring(const std::string str)
{


    int length = str.length();
    this->sequence = new char[length];

    //Assigning the elements of str to our object
    for (int i = 0; i < length; i++)
    {
        *(this->sequence + i) = str[i];
    }
    
    this->occupied = length;
    this->capacity = 0;
}


/**
 * @brief A copy Constructor
 * 
 * @param source 
 */
mystring::mystring(const mystring &source)
{

    int length = source.length();
    this->sequence = new char[length];

    this->insertSequanceAt(0, length, source.sequence);
    this->occupied = length;
    this->capacity = 0;
}

/**
 * @brief Destructor
 * 
 */
mystring::~mystring()
{
    delete[] this->sequence;
}

/**
 * @brief Swap function which exchange the elements of objects from where it has been called and the parameter which has been passed
 */
void mystring::swap(mystring& other){
    mystring tmp = other;

    //Resizing the parameter accordignly
    while (other.capacity - other.occupied < this->length())
    {
        other.resize();
    }
    other.insertSequanceAt(0,this->length(),this->sequence);
    other.occupied = this->occupied;

    //Resizing the object accordingly
    while (this->capacity - this->occupied < tmp.length())
    {
        this->resize();
    }

    this->insertSequanceAt(0, tmp.length() ,tmp.sequence);
    this->occupied = tmp.occupied;
}	

/**
 * @brief += operator with C string as parameter
 */
mystring &mystring::operator+=(const char addend[])
{


    int lengthOfAddend =strlen(addend);
    //Resizing the object if the addend is too large
    while (this->capacity - this->occupied < lengthOfAddend)
    {
        this->resize();
    }

    this->insertSequanceAt(this->length(), lengthOfAddend, addend);

    return *this;
}

/**
 * @brief += operator with mystring as parameter
 */
mystring &mystring::operator+=(const mystring &addend)
{
    //Resizing the object if the addend is too large
    while (this->capacity - this->occupied < addend.length())
    {
        this->resize();
    }

    this->insertSequanceAt(this->length(), addend.length(), addend.sequence);
    return *this;
}

/**
 * @brief += operator with char as parameter
 */
mystring &mystring::operator+=(const char addend)
{
    //Resizing the object if the capacity is equal to length
    if (this->capacity == this->length())
    {
        this->resize();
    }
    *(this->sequence + this->length()) = addend;
    this->occupied++;
    return *this;
}

/**
 * @brief [] operator with position as parameter
 */
char &mystring::operator[](size_t position)
{
    return *(this->sequence + position);
}

/**
 * @brief [] operator with position as parameter
 */
const char &mystring::operator[](size_t position) const
{
    return *(this->sequence + position);
}

/**
 * @brief = operator with mystring as parameter
 * I am adjusting also the length
 */
mystring &mystring::operator=(const mystring &source)
{
    //Adjusting the capacity if it is not enough
    while (this->capacity - this->occupied < source.length())
    {
        this->resize();
    }

    this->insertSequanceAt(0, source.length(), source.sequence);
    this->occupied = source.occupied;
    return *(this);
}

/**
 * @brief Global + operator with two mystring as parameters
 */
mystring stringexercise::operator+(const mystring &s1, const mystring &s2)
{
    mystring r = s1;
    return r += s2;
}

/**
 * @brief Global + operator with  mystring and char as parameters
 */
mystring stringexercise::operator+(const mystring &s1, const char *s2)
{
    mystring r = s1;
    return r += *(s2);
}

/**
 * @brief Global + operator with  char and mystring as parameters
 */
mystring stringexercise::operator+(const char *s1, const mystring &s2)
{
    mystring r = s2;
    return r += *(s1);
}

/**
 * @brief Global == operator with two mystrings as parameters
 */
bool stringexercise::operator==(const mystring &s1, const mystring &s2)
{
    if (s1.length() != s2.length()) {
        return false;
    }

    return strncmp(s1.sequence, s2.sequence, s1.length()) == 0;
}

/**
 * @brief Global == operator with  mystring and C string as parameters
 */
bool stringexercise::operator==(const mystring& s1, const char str[]) {

    if (s1.length() != strlen( str)) {
        return false;
    }
    return strncmp(s1.sequence, str, s1.length()) == 0;
}

/**
 * @brief Global != operator with two mystrings as parameters
 */
bool stringexercise::operator!=(const mystring &s1, const mystring &s2)
{
    if (s1.length() != s2.length()) {
        return true;
    }
    return strncmp(s1.sequence, s2.sequence, s1.length()) != 0;
}

/**
 * @brief Global > operator with two mystrings as parameters
 */
bool stringexercise::operator>(const mystring &s1, const mystring &s2)
{
    int smallerLength = std::min(s1.length(), s2.length());

    return std::strncmp(s1.sequence, s2.sequence,smallerLength) > 0;
}

/**
 * @brief Global < operator with two mystrings as parameters
 */
bool stringexercise::operator<(const mystring &s1, const mystring &s2)
{
    int smallerLength = std::min(s1.length(), s2.length());

    return std::strncmp(s1.sequence, s2.sequence, smallerLength) < 0;
}

/**
 * @brief Global <= operator with two mystrings as parameters
 */
bool stringexercise::operator<=(const mystring &s1, const mystring &s2)
{
   
    int smallerLength = std::min(s1.length(), s2.length());

    return std::strncmp(s1.sequence, s2.sequence, smallerLength) <= 0;
}

/**
 * @brief Global >= operator with two mystrings as parameters
 */
bool stringexercise::operator>=(const mystring &s1, const mystring &s2)
{
    int smallerLength = std::min(s1.length(), s2.length());

    return std::strncmp(s1.sequence, s2.sequence, smallerLength) >= 0;
}

/**
 * @brief Global << operator 
 */
std::ostream &stringexercise::operator<<(std::ostream &outs, const mystring &source)
{

    for (int i = 0; i < source.length(); i++)
    {
        outs << source[i];
    }
    return outs;
}

/**
 * @brief Global >> operator 
 */
std::istream &stringexercise::operator>>(std::istream &ins, mystring &target)
{
    std::istream::sentry sentry(ins);
    int next;
    while ((next = ins.get()) != ins.eof() && !std::isspace(next)){
         target+=next;
    }
       
    return ins;
}

/**
 * @brief resize() function doubles the capacity
 * 
 */
void mystring::resize()
{
    char *tmp = new char[this->capacity * 2];

    for (int i = 0; i < this->length(); i++)
    {
        *(tmp + i) = *(this->sequence + i);
    }

    this->capacity *= 2; // Doubling the capacity
    delete[] this->sequence; // Deleting the old collection
    this->sequence = tmp; // Assigning again
}


/**
 * @brief Inserts a sequance of characters in our object from specific place with given length
 * 
 * @param from starting place to be inserted in our collection
 * @param lenght how many elements will be inserted
 * @param ptr pointer to different collection
 */
void mystring::insertSequanceAt(int from, int lenght, const char *ptr)
{
    int j = 0;
    for (int i = from; i < from + lenght; i++, j++)
    {
        *(this->sequence + i) = *(ptr + j);
    }
    this->occupied += lenght;
}
