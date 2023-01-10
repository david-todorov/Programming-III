/**
 * @file Integral.cpp
 * @author David Todorov
 * @brief This functions calculates an aproximation of a integral
 */
#include <bits/stdc++.h>

/**
 * @brief Given functions
 */
double f(double x)
{
    return exp(-(x * x));
}

/**
 * @brief Calculates and integral using rectangle method
 */
double integral(double a, double b, int n)
{
    double width = (b - a) / n; // Width of every rectangle
    double tmpX = a;
    double area = 0;
    
    for (int i = 0; i < n; i++)
    {
        double height = f(tmpX); // calculating the current height of a partcular rectangle
        area += width * height;  // area of particular rectangle added to total area
        tmpX += width;           // starting point of the next rectangle
    }
    return area;
}
