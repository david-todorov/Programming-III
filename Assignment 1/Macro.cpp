/**
 * @file Macro.cpp
 * @author David Todorov
 * @brief Creating a macro which returns sum of the squares
 */
#include <iostream>
using namespace std;
#define QSUMME(a, b) (((a) * (a)) + ((b) * (b))) // Declaring the macro. We need parantheses for every argument a and b
int main()
{
    int i1 = 3;
    int i2 = 2;                         // Ergebnis:
    cout << QSUMME(i1, i2) << endl;     // 13
    cout << QSUMME(2 + i1, i2) << endl; // 29
    cout << QSUMME(i1, i2 + 1) << endl; // 18
    cout << 3 * QSUMME(i1, i2) << endl; // 39
}
