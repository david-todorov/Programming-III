#include <iostream>
using namespace std;

void f1(char *);
void f2(const char *);
void f3(char *const);
void f4(const char *const);

int main()
{
    char *p1, a[10];
    const char *p2 = "hallo";
    char *const p3 = a;
    const char *const p4 = "hallo";

    f1("hallo");
    f1(a);
    f1(p1);
    f1(p2);
    f1(p3);
    f1(p4);

    f2("hallo");
    f2(a);
    f2(p1);
    f2(p2);
    f2(p3);
    f2(p4);

    f3("hallo");
    f3(a);
    f3(p1);
    f3(p2);
    f3(p3);
    f3(p4);

    f4("hallo");
    f4(a);
    f4(p1);
    f4(p2);
    f4(p3);
    f4(p4);

    return 1;
}