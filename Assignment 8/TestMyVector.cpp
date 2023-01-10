/**
 * @file TestMyVector.cpp
 * @author David Todorov
 * @brief This file tests some of the functionalities of MeVector class
 */
#include <iostream>
#include "MyVector.h"
#include "Person.h"
using namespace std;

void testWithprimitiveDataTypes(){
    cout << "Testing the constructors" << endl;
   MyVector<int> v1;
   MyVector<int> v2(10);
   MyVector<int> v3(v2);
   MyVector<int> v4(2,10);
   cout << v1 << endl;
   cout << v2 << endl;
   cout << v3 << endl;
   cout << v4 << endl;
   cout << "--------------------------" << endl;
   cout << "Testing the set/remove operations" << endl;
   v2.set(0,4); 
   v2.set(1,5); 
   v2.set(2,6); 
   cout << v2 << endl;
   
   v2.remove(0); 
   cout << v2 << endl;
   v2.remove(1);; 
   cout << v2 << endl;
   v2.remove(0);; 
   cout << v2 << endl;
   cout << "--------------------------" << endl;

    cout << "Testing the insert operations" << endl;
    v4.insert(1,69);
    cout << v4 << endl;
    v3.insert(0,420);
    v4.insert(1,v3);
    cout << v4 << endl;
    cout << "--------------------------" << endl;
    cout << "Testing other functions" << endl;
    cout << v4[1] << endl;
    v4[1] = 4;
    cout << v4[1] << endl;
    v1 = v4;
    cout << v1 << endl;
    cout << v3 << endl;
    v1.swap(v3);
     cout << v1 << endl;
    cout << v3 << endl;
}
void testWithObjects(){
   cout << "Testing the constructors" << endl;
   MyVector<Person> v1;
   MyVector<Person> v2(10);
   MyVector<Person> v3(v2);
   MyVector<Person> v4(Person("David",21),3);
   cout << v1 << endl;
   cout << v2 << endl;
   cout << v3 << endl;
   cout << v4 << endl;
   cout << "--------------------------" << endl;
   cout << "Testing the set/remove operations" << endl;
   v2.set(0,Person("Ivan",20)); 
   v2.set(1,Person("Dragan",19)); 
   v2.set(2,Person("Toshko",18)); 
   cout << v2 << endl;
   v2.remove(0); 
   cout << v2 << endl;
   v2.remove(1);; 
   cout << v2 << endl;
   v2.remove(0);; 
   cout << v2 << endl;
   cout << "--------------------------" << endl;

   cout << "Testing the insert operations" << endl;
    v4.insert(1,Person("Violina",52));
    cout << v4 << endl;
    v3.insert(0,Person("Neli",81));
    v4.insert(1,v3);
    cout << v4 << endl;
    cout << "--------------------------" << endl;
    cout << "Testing other functions" << endl;
    cout << v4[1] << endl;
    v4[1] = Person("Aleksandra",24);
    cout << v4[1] << endl;
    v1 = v4;
    cout << v1 << endl;
    cout << v3 << endl;
    v1.swap(v3);
    cout << v1 << endl;
    cout << v3 << endl;

}
int main(void)
{

    testWithprimitiveDataTypes();
    testWithObjects();
    return 0;
}
