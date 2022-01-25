#ifndef DOUBLEDYNAMICLINKEDLIST_H
#define DOUBLEDYNAMICLINKEDLIST_H
#include "PermanentEmployee.h"
#include "Date.h"
struct Node {
   PermanentEmployee* data;
   struct Node *prev;
   struct Node *next;
};

class DoubleDynamicLinkedList
{
    public:
        DoubleDynamicLinkedList();
        virtual ~DoubleDynamicLinkedList();
        void insertAtFront(/*Node** head,*/ PermanentEmployee* Employee);
        void insertAtEnd(/*Node** head,*/ PermanentEmployee* Employee);
        void insertAfter(Node* prev_node, PermanentEmployee* Employee);
        void sortList();
        void removeAtFront(Node**head);
        void removeAtEnd(Node**head);
        void removeNode(Node* node);
        Node* returnEmp(int id);
        bool searchEmp(int id);
        bool searchEmpByApp(Date &date);
        int* returnIDs(int size);
        Date* returnDates(int size);
        Date* returnBiggerDates(Date date);
        Date* returnEqualYearDates(int year);
        Date* returnEqualTitleDates(string title);
        int* returnSmallerBDates(Date date);
        int* returnMonthIDs(int month);
        int returnMonthIDlength(int month);
        int returnDateBiggerlength(Date date);
        int returnEqualTitlelength(string title);
        int returnDateSmallerlength(Date date);
        int returnEqualYearlength(int year);
        void traverseList();
        void traverseListAppDate(Date date);
        void traverseListBDate(Date date);
        void searchAndPrint(int id);
        void editEmp(int id, string title, float salary);
        void deleteEmp(int id);
        Node* head = NULL;
        Node* tail=NULL;
    protected:

    private:
};

#endif // DOUBLEDYNAMICLINKEDLIST_H
