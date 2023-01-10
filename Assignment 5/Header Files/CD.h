/**
 * @file CD.h
 * @author David Todorov
 * @brief header file for class CD which is derived from Medium
 */
#ifndef CD_H_
#define CD_H_

#include "Medium.h"

class CD : public Medium{
    public:
            CD(string abbreviation, string author, string title, int yearOfPubl);
};

#endif