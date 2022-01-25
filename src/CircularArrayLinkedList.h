#ifndef CIRCULARARRAYLINKEDLIST_H
#define CIRCULARARRAYLINKEDLIST_H
#include "TemporaryEmployee.h"
struct nodetype {
  TemporaryEmployee* info;
  int next;
};

class CircularArrayLinkedList
{
    public:
        CircularArrayLinkedList();
        virtual ~CircularArrayLinkedList();
        nodetype node[20];
        void insertEmp(TemporaryEmployee* emp);
        void deleteEmp(int id);
        void initializeList();
        void traversePrint();
        void printEmp(int id);
        bool empExists(int id);
        void updateEmp(int id,string title,float salary);
        void setAvail();
        void sortList();
    protected:

    private:
        int avail=0;
        int currentsize=0;
};

#endif // CIRCULARARRAYLINKEDLIST_H
