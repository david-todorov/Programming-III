/**
 * @file Error.h
 * @author David Todorov
 * @brief Header file for custom exception named Error derived from class exception
 */
#ifndef ERROR_H_
#define ERROR_H_
#include <iostream>
using namespace std;

class Error : public exception
{
    //* private attributes
private:
        string message;
    //* Constructor and method getMessage()
public:
    Error(string message);
    string getMessage();
};




#endif