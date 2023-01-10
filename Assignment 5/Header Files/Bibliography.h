/**
 * @file Bibliography.h
 * @author David Todorov
 * @brief Header file for Bivliograhpy file, manages a collection of Medium objects
 */
#ifndef BIBLIOGRAPHY_H
#define BIBLIOGRAPHY_H
#include "Medium.h"

class Bibliography{

        /**
         * @brief private attributes
         * 
         */
        private:
                int index; //* Points to the last inserted element
                int internalSize; //* Maximum capacity of the collection
                Medium* mediumData[]; //*Array of pointers, the collection itself
                
                

        public:
                Bibliography(int size);
               
               /**
                * @brief Inserting new entity into the collection
                * 
                * @param pointer to Medium derived object object
                */
                void insert( Medium *media);
                /**
                 * @brief Overriding the operator [], such way its searches for an entity by given abbreviation and returns pointer to it
                 * 
                 * @param abbr unique 
                 * @return Medium pointer
                 */
                Medium* operator[] (string abbr);
                /**
                 * @brief Overriding the operator << such way it returns the whole bibliography, also a friend function
                 * @return ostream& 
                 */
                friend ostream& operator<<(ostream& os, const Bibliography& bibliography);
};

#endif