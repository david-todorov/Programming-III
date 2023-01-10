/**
 * @file Vector.cpp
 * @author David Todorov
 * @brief This is the Vector class, which implements simple Vector functionalities
 */
#include "Vector.h"
#include <iostream>

/**
 * @brief Two constanst which are used when some of the parameters ar omitted
 */
const int DEF_DIM = 2;
const double DEF_INITVALUE = 0.0;

/**
 * @brief Construct a new Vector
 * @param dimensions numbers of elements, 2 elements are created if the parameter is omitted
 * @param initValue initial value for all of the elements. If it is omitted the value of 0.o is being used
 */
Vector::Vector(int dimensions, double initValue)
{
    //* Setting up the dimensions
    this->dimensions = dimensions;
    //* New allocation of memory
    this->ptrArray = new double[this->dimensions];
    //* Setting the initial value for each element
    for (int i = 0; i < this->dimensions; i++)
    {
        *(this->ptrArray + i) = initValue;
    }
}

/**
 * @brief Calling the main construcor using a feature provided in c++ 11
 * 
 * @param dimensions Only the size of the vector with initial value of 0.0
 */
Vector::Vector(int dimensions) : Vector(dimensions, DEF_INITVALUE){};
/**
 * @brief Calling the main construcor using a feature provided in c++ 11
 * 
 * @param initValue Only the initial value of the vector and dimension of 2
 */
Vector::Vector(double initValue) : Vector(DEF_DIM, initValue){};

/**
 * @brief Copy constructor, creates a deep copy by copying the elements of otherVecor
 * 
 * @param otherVecor the other vectot from which the elements will be copied 
 */
Vector::Vector(const Vector &otherVecor)
{
    this->ptrArray = new double[otherVecor.dimensions];
    this->dimensions = otherVecor.dimensions;
    for (int i = 0; i < this->dimensions; i++)
    {
        *(this->ptrArray + i) = *(otherVecor.ptrArray + i);
    }
}

/**
 * @brief Destroy the Vector by deallocating the memory of the internal array
 * 
 */
Vector::~Vector()
{
    delete[] this->ptrArray;
}

/**
 * @brief Overloading the operator [] and if the index is out of range, terminates the program
 * @return double& the elements at particular place 
 */
double& Vector::operator[](int index)
{

    if (index < 0 || index > (this->dimensions - 1))
    {
        std::cout << "Array index out of bound, exiting";
        exit(0);
    }
    return *(this->ptrArray + index);
}

/**
 * @brief Overloading the operator = by creating a deep copy
 * @return the newly created copy 
 */
Vector& Vector::operator=(const Vector& other){

    if(this->dimensions != other.dimensions){
        this->~Vector();
        this->dimensions = other.dimensions;
        this->ptrArray = new double[this->dimensions];
    }
    for (int i = 0; i < this->dimensions; i++)
    {
        *(this->ptrArray + i) = *(other.ptrArray + i);
    }
    return *this;
}

/**
 * @brief Sets a element at specific place using the index
 * 
 * @param index where to set a value 
 * @param value which will be set
 */
void Vector::set(int index, double value)
{
    this->operator[](index) = value;
}

/**
 * @brief Get specific element from specific place
 * @return The element from particular place 
 */
double Vector::get(int index)
{
    return this->operator[](index);
}

/**
 * @brief Overloading the operator << with format (el1, el2, el3, ...)
 * @return formated stream
 */
std::ostream &operator<<(std::ostream &os, const Vector &other)
{
    os << "(";
    for (int i = 0; i < other.dimensions; i++)
    {
        if (i == other.dimensions - 1)
        {
            os << *(other.ptrArray + i);
        }
        else
        {
            os << *(other.ptrArray + i) << ", ";
        }
    }
    os << ")" << std::endl;
    return os;
}


