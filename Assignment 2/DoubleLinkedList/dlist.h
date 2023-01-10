

//! Struct of a list item
struct DListElem
{
    int info;
    DListElem* next;
    DListElem* previous;
};

//! Struc of first element and the last one
struct DList
{
    DListElem* first;
    DListElem* last;
};

void initializeDList(DList & dl);
void put(DList& dl, int val);
bool get(DList& dl, int &val);
bool isEmpty(DList dl);   
void printList(DList & dl);

