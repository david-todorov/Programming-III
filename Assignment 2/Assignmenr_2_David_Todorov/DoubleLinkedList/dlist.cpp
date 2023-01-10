#include "dlist.h"
#include <iostream>
using namespace std;

void initializeDList(DList &dl)
{
    dl.first = nullptr;
    dl.last = nullptr;
}
/**
 * @brief Adding element
 * 
 * @param dl 
 * @param val value to be inserted
 */
void put(DList &dl, int val)
{
    DListElem *dListElem = new DListElem();
    dListElem->info = val;
    dListElem->previous = nullptr;

    //If the list is empty
    if (isEmpty(dl))
    {
        //Both fisrt and last point the the same element
        dListElem->next = nullptr;

        dl.first = dl.last = dListElem;
    }
    else
    {
        //Otherwise a new element is added
        dl.first->previous = dListElem;
        dListElem->next = dl.first;
        dl.first = dListElem;
    }
}
/**
 * @brief Returns value from the end of the list 
 * 
 * @param dl 
 * @param val 
 * @return true when is possible a.k.a. when the list is not empty
 * @return false when is empty
 */
bool get(DList &dl, int &val)
{
    if (isEmpty(dl))
    {
        return false;
    }
    else
    {
        // When there is only one element
        if (dl.first == dl.last)
        {
            val = dl.first->info;
            delete dl.first; //Releasing the memory
        }
        else
        {
            //When there are more elements
            val = dl.last->info;
            DListElem *le = dl.last->previous;
            delete dl.last;
            dl.last = le;
            dl.last->next = nullptr;
        }

        return true;
    }
}
/**
 * @brief Checks wheather a List is empty
 * 
 * @param dl 
 * @return true when is empty
 * @return false when is not empty
 */
bool isEmpty(DList dl)
{

    if (dl.first == nullptr || dl.last == nullptr)
    {
        return true;
    }
    return false;
}