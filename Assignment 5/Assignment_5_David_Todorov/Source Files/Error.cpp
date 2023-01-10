/**
 * @file Error.cpp
 * @author David Todorov
 * @brief Implementation of class Error
 */
#include "../Header Files/Error.h"

Error::Error(string message){
    this->message = message;
}

string Error::getMessage(){
    return this->message;
}