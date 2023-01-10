#include <iostream>
using namespace std;

class KL1
{
private:
    string name;

public:
    int i;
    KL1()
    {
        name = "### not defined ###";
        i = 0;
    }
    KL1(string n, int v) : name(n), i(v) {}
    void print()
    {
        cout << name << ": " << i << endl;
    }
};

class KL2
{
private:
    void meth2(KL1 &ok, int wert)
    {
        ok.i = wert;
        wert = 888;
    }

public:
    void test()
    {
        KL1 k0("obj1", 10);
        KL1 k1("obj2", 20);
        KL1 &k2 = k1;
        KL1 feld[3];
        feld[0] = k0;
        feld[1] = k1;
        feld[2] = k2;
        feld[0].print();
        feld[1].print();
        feld[2].print();
        int j = 42;
        meth2(feld[0], j);
        feld[2].i = 999;
        feld[0].print();

        feld[1].print();
        feld[2].print();
        cout << "j = " << j << endl;
    }
};

int main()
{
    KL2 o2;
    o2.test();
    //obj1: 10
    //obj2: 20
    //obj2: 20
    //obj1: 42
    //obj2: 20
    //obj2: 999
    //j = 42

    return 1;
}