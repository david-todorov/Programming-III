/**
 * @file Vector.h
 * @author David Todorov
 * @brief Header file for Vector.cpp
 */
#include <iostream>
class Vector
{
    
private:
    //* Size of the Vector
    int dimensions;
    //* Pointer to the first value
    double *ptrArray;
public:
    //* Different constructors
    Vector(int dimensions, double initValue);
    Vector(int dimensions);
    Vector(double initValue);
    //* The copy constructor
    Vector(const Vector& copy);
    //* The Destructor
    ~Vector();
    double get(int index);
    void set(int index, double value);
    //* Overloading the operator []
    double& operator[](int index);
    //*  Overloading the operator =
    Vector& operator=(const Vector& other);
    //* Overloading the operator <<
    friend std::ostream& operator<<(std::ostream& os, const Vector& other);
};




