/**
 * @file List.cpp
 * @author David Todorov
 * @brief Some functionalities for single linked list
 * 
 */
#include "List.h"
#include <iostream>
using namespace std;

/**
 * @brief Printing the list's elements on one line
 * 
 * @param lst The list
 */
void printList(List lst)
{
    for (; lst != 0; lst = lst->next)
    {
        cout << lst->info << " ";
    }
    cout << endl;
}

/**
 * @brief Inserting an element at the very end of the list
 * 
 * @param lst 
 * @param info 
 */
void insertLast(List &lst, int info)
{
    ListElem *newListEl = new ListElem();
    newListEl->info = info;

    //! If the list is empty the pointer to the list points to the first element
    if (lst == emptyList)
    {
        lst = newListEl;
    }
    else
    {
        //! Creating the variable for the start of the list
        ListElem* begining = lst;
        //! Iterating until finding the last element
        for (; lst != 0; lst = lst->next)
        {
            if (lst->next == 0)
            {
                //! Assigning the lastElement.next to the freshly created element
                lst->next = newListEl;
                break;
            }
        }
        //! It needs to point back to the begining
        lst = begining;
    }
}

/**
 * @brief Reversing the list
 * 
 * @param lst 
 */
void reverseList(List &lst)
{
    //! If the list consists of more than one element
    if (lst->next != 0)
    {
        //! Creating pointers such as previous, current and next element
        ListElem *ptrPrev = 0;
        ListElem *ptrCurrent = lst;
        ListElem *ptrNext = 0;
        while (ptrCurrent != 0)
        {
            //! Swapping the directions
            ptrNext = ptrCurrent->next;
            ptrCurrent->next = ptrPrev;
            ptrPrev = ptrCurrent;
            ptrCurrent = ptrNext;
        }
        //! Assigning the new value to the lst
        lst = ptrPrev;
    }
}
