#include <iostream>
#include <stdlib.h>
#include "../Header Files/Bibliography.h"
#include "../Header Files/Book.h"
#include "../Header Files/Article.h"
#include "../Header Files/Error.h"
using namespace std;

void testBibliography()
{
    // create bibliography
    Bibliography myBibliography(10);
    Book *b1 = new Book("Ra01",
                        "Dietmar Ratz",
                        "Grundkurs Programmieren in Java",
                        2001,
                        "Hanser-Verlag");
    Book *b2 = new Book("Kr03",
                        "Guido Krueger",
                        "Handbuch der Java-Programmierung",
                        2003,
                        "Addison-Wesley");
    Article *a1 = new Article("Pa72",
                              "D. L. Parnas",
                              "On the Criteria To Be Used in Decomposing Systems into",
                              1972,
                              "Communications of the ACM",
                              15,
                              1053);

    try
    {
        myBibliography.insert(b1);
        myBibliography.insert(b2);
        myBibliography.insert(a1);
        cout << "Bibliography:" << endl << myBibliography; 
        cout << endl << (*myBibliography["Pa72"]).toString() << endl;
             
    }
    catch (Error f)
    {
        cout << endl
             << f.getMessage() << endl;
    }
    
    
}
int main(int argc, char *argv[])
{
    testBibliography();
    cin.sync();
    cin.get();
    return 0;
}
