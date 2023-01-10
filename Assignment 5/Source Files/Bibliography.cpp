/**
 * @file Bibliography.cpp
 * @author David Todorov
 * @brief Implementation of class Bibliography
 */
#include "../Header Files/Bibliography.h"
#include "../Header Files/Error.h"

Bibliography::Bibliography(int size)
{
    this->index = 0;
    this->internalSize = size;
    this->mediumData[size];
}
/**
 * @brief Method which inserts new entity into the Bibliography, if the maximum capacity is reached, throws an exception 
 */
void Bibliography::insert(Medium *media)
{

    if (this->index >= this->internalSize)
    {
        throw Error("The amount of space in Bibliography has exceeded");
    }
    this->mediumData[this->index] = media;
    this->index++;
}
/**
 * @brief Overriding the operator [] such way that it searches for entity by given unique abbreviation
 * if the entity is not founded the null pointer is returned
 */
Medium *Bibliography::operator[](string abbr)
{

    for (int i = 0; i <= this->index; i++)
    {
        if (this->mediumData[i]->getAbbreviation() == abbr)
        {
            return this->mediumData[i];
        }
    }
    return nullptr;
}

/**
 * @brief Overriding the operator << such way that returns ostream in formated way
 */
ostream& operator<<(ostream& os, const Bibliography& bibliography)
{

    for (int i = 0; i <= bibliography.index; i++)
    {
        os << bibliography.mediumData[i]->toString() << endl;
    }
    return os;
}
