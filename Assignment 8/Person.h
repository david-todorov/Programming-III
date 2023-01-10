#include <string>
#include <iostream>
using namespace std;
class Person
{
private:
    string name;
    int age;
public:
    Person(string name , int age);
    Person();
     friend std::ostream& operator<<(std::ostream& out, const Person& obj) /* noexcept */ {
        out << "Name: " << obj.name << " Age: " << obj.age;
      return out;
   }
};
Person::Person(){

}
Person::Person(string name , int age)
{
    this->name =name;
    this->age = age;
}


