
/**
 * @file MyVector.h
 * @author David Todorov
 * @brief Custom template class
 */
#include <string>
#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class MyVector
{
   
    const int INIT_SIZE = 2;
    const int DEFAULT_RESIZE_FACTOR = 2;

private:
    T *data;
    int occupied;
    int capacity;
    void rightShift(int start, int steps);
    void leftShift(int start, int steps);
    void insertSequanceAt(int from, int lenght, const T *ptr);
   

public:
    MyVector();
    MyVector(int initSize);
    MyVector(const MyVector<T> &vector);
    MyVector(const T value, int initSize);
    virtual ~MyVector();

    void resize(int factor);
    T &get(const int index);
    void set(int index, const T &value);
    int size();
    string toString();
    bool remove(int position);
    void insert(int position, const T &value);
    void insert(int position, const MyVector<T> &vector);
    void swap(MyVector<T> &other);
    T &operator[](int);
    T operator[](int) const;

    MyVector<T> &operator=(const MyVector<T> &source);
    template <class U>
    friend ostream &operator<<(ostream &os, const MyVector<U> &L);
};

/**
 * @brief Construct a vector with default size
 */
template <class T>
MyVector<T>::MyVector()
{
    this->data = new T[INIT_SIZE];
    this->occupied = 0;
    this->capacity = INIT_SIZE;
};

/**
 * @brief Construct a vector with given size
 */
template <class T>
MyVector<T>::MyVector(int initSize)
{
    this->data = new T[initSize];
    this->occupied = 0;
    this->capacity = initSize;
};

/**
 * @brief Construct a vector from another vector, copy constructor

 * @param copy from which is being constructed
 */
template <class T>
MyVector<T>::MyVector(const MyVector<T> &copy)
{
    this->data = new T[copy.capacity];
    this->occupied = 0;
    this->capacity = copy.capacity;

    this->insertSequanceAt(0, copy.occupied, copy.data);
};

/**
 * @brief Construct a new vector with given size and default values 
 */
template <class T>
MyVector<T>::MyVector(const T value, int initSize)
{
    this->data = new T[initSize];
    this->occupied = 0;
    this->capacity = initSize;

    for (int i = 0; i < this->capacity; i++)
    {
        this->set(i, value);
    }
}
/**
 * @brief Destroying the vector
 */
template <class T>
MyVector<T>::~MyVector()
{
    delete[] this->data;
};

/**
 * @brief Returns the number of elements in the vector
 */
template <class T>
int MyVector<T>::size()
{
    return this->occupied;
}

/**
 * @brief Set a specific value to specific position, throws an exception if the position is invalid 
 */
template <class T>
void MyVector<T>::set(int position, const T &value)
{
  
    if (position < 0 || position >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }

    *(this->data + position) = value;
    if (position == this->occupied)
    {
        this->occupied++;
    }
}

/**
 * @brief Resizes the vector from a given factor, which multiplies the capacity
 */
template <class T>
void MyVector<T>::resize(int factor)
{
    T *tmp = new T[this->capacity * factor];

    for (int i = 0; i < this->occupied; i++)
    {
        *(tmp + i) = *(this->data + i);
    }

    this->capacity *= factor;
    delete[] this->data;
    this->data = tmp;
}

/**
 * @brief Returns a at a given position,throws an exception if the position is invalid 
 */
template <class T>
T &MyVector<T>::get(int position)
{
    if (position < 0 || position >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }
    return *(this->data + position);
}
/**
 * @brief Returns a string representations of the vector (el1, el2, el3, ...)
 * 
 * @tparam T 
 * @return string 
 */
template <class T>
string MyVector<T>::toString()
{
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

/**
 * @brief Removes one elements at given position and closes the gap, shifts the vector to the left, returns true if its possible otherwise false
 */
template <class T>
bool MyVector<T>::remove(int position)
{
    if (position < 0 || position >= this->occupied)
    {
        return false;
    }
    if (position != this->occupied - 1)
    {
        this->leftShift(position, 1);
    }
    this->occupied--;
    return true;
}
/**
 * @brief Inserts a value at given position, fisrts creates a space by right shifting
 */
template <class T>
void MyVector<T>::insert(int position, const T &value)
{

    if (position < 0 || position >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }

    if (this->occupied == this->capacity)
    {
        this->resize(DEFAULT_RESIZE_FACTOR);
    }

    this->rightShift(position, 1);
    this->data[position] = value;
    this->occupied++;
}
/**
 * @brief Inserts a another vector at given position, fisrts creates a space by right shifting
 */
template <class T>
void MyVector<T>::insert(int position, const MyVector<T> &vector)
{
    if (position < 0 || position >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }

    while (this->capacity - this->occupied < vector.occupied)
    {
        this->resize(DEFAULT_RESIZE_FACTOR);
    }

    this->rightShift(position, vector.occupied);

    this->insertSequanceAt(position, vector.occupied, vector.data);
}
/**
 * @brief Total swapping of the vectors
 */
template <class T>
void MyVector<T>::swap(MyVector<T> &other)
{
    MyVector<T> tmp = other;

    // Resizing the parameter accordignly
    while (other.capacity - other.occupied < this->occupied)
    {
        other.resize(DEFAULT_RESIZE_FACTOR);
    }
    other.insertSequanceAt(0, this->occupied, this->data);
    other.occupied = this->occupied;

    // Resizing the object accordingly
    while (this->capacity - this->occupied < tmp.occupied)
    {
        this->resize(DEFAULT_RESIZE_FACTOR);
    }
    this->insertSequanceAt(0, tmp.occupied, tmp.data);
    this->occupied = tmp.occupied;
}

/**
 * @brief Right shifting with given steps
 */
template <class T>
void MyVector<T>::rightShift(int start, int steps)
{

    for (int i = this->occupied - 1; i >= start; i--)
    {
        *(this->data + i + steps) = *(this->data + i);
    }
}

/**
 * @brief Left shifting, keep in mind it overwrites the elements, it does not create space
 */
template <class T>
void MyVector<T>::leftShift(int start, int steps)
{
    int j = 0;
    for (int i = start + steps; i < this->occupied; i++, j++)
    {

        *(this->data + j) = *(this->data + i);
    }
   
}

/**
 * @brief Insert sequance at given position, also increases the occupation accordingly
 */
template <class T>
void MyVector<T>::insertSequanceAt(int from, int lenght, const T *ptr)
 {
        int j = 0;
        for (int i = from; i < from + lenght; i++, j++)
        {
            *(this->data + i) = *(ptr + j);
        }
        this->occupied += lenght;
    };

/**
 * @brief Overwriting the [] opeartor
 */
template <class T>
T &MyVector<T>::operator[](int index)
{
    if (index < 0 || index >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }
    return *(this->data + index);
}

/**
 * @brief Overwriting the [] opeartor
 */
template <class T>
T MyVector<T>::operator[](int index) const
{
    if (index < 0 || index >= this->capacity)
    {
        throw std::out_of_range("The index is out of bounds of the array");
    }
    return *(this->data + index);
}

/**
 * @brief Overwriting the = opeartor
 */
template <class T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &source)
{
    while (this->capacity - this->occupied < source.occupied)
    {
        this->resize(DEFAULT_RESIZE_FACTOR);
    }

    this->insertSequanceAt(0, source.occupied, source.data);
    this->occupied = source.occupied;
    return *(this);
}

/**
 * @brief Overwriting the << opeartor, keep in mind that in order to work nicely, every object of class T should overload the operator << accordingly
 */
template <class T>
ostream &operator<<(ostream &os, const MyVector<T> &vector)
{

    os << "(";
    for (int i = 0; i < vector.occupied; i++)
    {
        if (i == vector.occupied - 1)
        {
            os << *(vector.data + i);
        }
        else
        {
            os << *(vector.data + i) << ", ";
        }
    }
    os << ")";

    return os;
}