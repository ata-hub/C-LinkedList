#include "DoubleDynamicLinkedList.h"
#include "PermanentEmployee.h"
#include <iostream>
#include "Date.h"
using namespace std;
DoubleDynamicLinkedList::DoubleDynamicLinkedList()
{
    //ctor
}

DoubleDynamicLinkedList::~DoubleDynamicLinkedList()
{
    //dtor
}

void DoubleDynamicLinkedList:: insertAtFront(/*struct Node** head,*/ PermanentEmployee* Employee)
{
   //allocate memory for New node
   struct Node* newNode = new Node();

   //assign data to new node
   newNode->data = Employee;

   //new node is head and previous is null, since we are adding at the front
   newNode->next = (head);
   newNode->prev = NULL;

   //previous of head is new node
   if ((head) != NULL)
   (head)->prev = newNode;

   //head points to new node
   (head) = newNode;
}
void DoubleDynamicLinkedList::sortList(){

    int swapped, i;
    struct Node *ptr1;
    struct Node *ptr2 = NULL;

    /* Checking for empty list */
    if (head == NULL){
        return;
    }
    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2)
        {
            if (ptr1->data->Getappointment() > ptr1->next->data->Getappointment())
            {
                swap(ptr1->data, ptr1->next->data);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
    while (swapped);





}
void DoubleDynamicLinkedList:: insertAfter(struct Node* prev_node, PermanentEmployee* Employee)
{
   //check if prev node is null
   if (prev_node == NULL) {
   cout<<"Previous node is required , it cannot be NULL";
   return;
    }
   //allocate memory for new node
   struct Node* newNode = new Node();

   //assign data to new node
   newNode->data = Employee;

   //set next of newnode to next of prev node
   newNode->next = prev_node->next;

   //set next of prev node to newnode
   prev_node->next = newNode;

   //now set prev of newnode to prev node
   newNode->prev = prev_node;

   //set prev of new node's next to newnode
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
}
void DoubleDynamicLinkedList:: insertAtEnd(/*struct Node** head,*/ PermanentEmployee* Employee)
{
   //allocate memory for node
   struct Node* newNode = new Node();

   struct Node* last = head; //set last node value to head

   //set data for new node
   newNode->data = Employee;

   //new node is the last node , so set next of new node to null
   newNode->next = NULL;

   //check if list is empty, if yes make new node the head of list
   if (head == NULL) {
   newNode->prev = NULL;
   head = newNode;
   tail=newNode;
    return;
}

//otherwise traverse the list to go to last node
while (last->next != NULL)
last = last->next;

//set next of last to new node
last->next = newNode;

//set last to prev of new node
newNode->prev = last;
tail=newNode;
return;
}
void DoubleDynamicLinkedList:: removeNode(Node* n){
    // if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		if(n->next==NULL){
            //only element in the list

            head=NULL;
            tail=NULL;
		}
		else{

		head = n->next; //the next node will be front of list headin başına * gelebilir
		head->prev = NULL;
		}
	}
	// if node to be deleted is last node of list
	else if(n->next == NULL)
	{
		tail = n->prev;   // the previous node will be last of list
		tail->next = NULL;
	}
	else
	{
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);

}
bool DoubleDynamicLinkedList::searchEmp(int id){
    struct Node* current=new Node();
    if(head==NULL){

        return false;
    }
    current=head;
    while(current!=NULL){
    if(id==current->data->Getid()){
        return true;
    }
        current=current->next;
    }
    return false;
}
/*bool DoubleDynamicLinkedList::searchEmpByApp(Date &date){
    struct Node* current=new Node();
    if(head==NULL){
        cout<<"head is null";
        return false;
    }
    current=head;
    while(current!=NULL){
    if(date==current->data->Getappointment()){
        return true;
    }
        current=current->next;
    }
    return false;
}*/
void DoubleDynamicLinkedList::traverseList(){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        cout<<current->data<<endl;
        current=current->next;
    }
}
void DoubleDynamicLinkedList::traverseListAppDate(Date date){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getappointment()==date){
            cout<<current->data<<endl;
        }

        current=current->next;
    }
}

void DoubleDynamicLinkedList::traverseListBDate(Date date){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getbirthdate()==date){
            cout<<current->data<<endl;
        }

        current=current->next;
    }
}

void DoubleDynamicLinkedList::searchAndPrint(int id){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getid()==id){
            cout<<current->data<<endl;
            //return;
        }

        current=current->next;
    }
}
void DoubleDynamicLinkedList::editEmp(int id,string title, float salary ){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getid()==id){
            current->data->Setsalary(salary);
            current->data->Settitle(title);
            return;
        }

        current=current->next;
    }
}
Node* DoubleDynamicLinkedList::returnEmp(int id){
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getid()==id){
            //cout<<"returning node with id: "<<id<<endl;
            return current;
        }
        current=current->next;
    }

}
int* DoubleDynamicLinkedList::returnIDs(int size){
    if(size==0){
        return NULL;
    }
    else{
    int* arr=new int[size];
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        int a=-1;
        int* b=&a;
        return b;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){

        arr[count]=current->data->Getid();

        current=current->next;
        count++;
    }
    return arr;
    }

}
int* DoubleDynamicLinkedList::returnMonthIDs(int month){

    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;
        int a=-1;
        int* b=&a;
        return b;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getbirthdate().Getmonth()==month){
            count++;

        }
        current=current->next;
    }
    int* arr=new int[count];
    int count2=0;
    struct Node* current2=new Node();
    current2=head;
    while(current2!=NULL){
        if(current2->data->Getbirthdate().Getmonth()==month){
            arr[count2]=current2->data->Getid();
            count2++;
        }


        current2=current2->next;

    }
    return arr;


}
int DoubleDynamicLinkedList::returnMonthIDlength(int month){
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;


        return -1;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getbirthdate().Getmonth()==month){
            count++;

        }
        current=current->next;
    }
    return count;



}
int DoubleDynamicLinkedList::returnDateBiggerlength(Date date){
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;


        return -1;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getappointment()>date){
            count++;

        }
        current=current->next;
    }
    return count;
}
int DoubleDynamicLinkedList::returnEqualYearlength(int year){
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;


        return -1;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getappointment().Getyear()==year){
            count++;

        }
        current=current->next;
    }
    return count;
}

int DoubleDynamicLinkedList::returnEqualTitlelength(string title){
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;


        return -1;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Gettitle()==title){
            count++;

        }
        current=current->next;
    }
    return count;
}

int DoubleDynamicLinkedList::returnDateSmallerlength(Date date){
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;


        return -1;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getbirthdate()< date){
            count++;

        }
        current=current->next;
    }
    return count;
}

Date* DoubleDynamicLinkedList::returnDates(int size){
    Date* arr=new Date[size];
    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;

        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){

        arr[count]=current->data->Getappointment();

        current=current->next;
        count++;
    }
    return arr;

}
Date* DoubleDynamicLinkedList::returnBiggerDates(Date date){

    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;

        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getappointment()>date){
            count++;
        }
        current=current->next;
    }

    struct Node* current2=new Node();
    current2=head;
    Date* arr=new Date[count];
    int count2=0;
    while(current2!=NULL){
        if(current2->data->Getappointment()>date){
            arr[count2]=current2->data->Getappointment();
            count2++;
        }
        current2=current2->next;
    }


    return arr;

}

int* DoubleDynamicLinkedList::returnSmallerBDates(Date date){

    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;

        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getbirthdate()<date){
            count++;
        }
        current=current->next;
    }

    struct Node* current2=new Node();
    current2=head;
    int* arr=new int[count];
    int count2=0;
    while(current2!=NULL){
        if(current2->data->Getbirthdate()<date){
            arr[count2]=current2->data->Getid();
            count2++;
        }
        current2=current2->next;
    }


    return arr;

}

Date* DoubleDynamicLinkedList::returnEqualTitleDates(string title){

    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;

        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Gettitle()==title){
            count++;
        }
        current=current->next;
    }

    struct Node* current2=new Node();
    current2=head;
    Date* arr=new Date[count];
    int count2=0;
    while(current2!=NULL){
        if(current2->data->Gettitle()==title){
            arr[count2]=current2->data->Getappointment();
            count2++;
        }
        current2=current2->next;
    }


    return arr;

}

Date* DoubleDynamicLinkedList::returnEqualYearDates(int year){

    int count=0;
    if(head==NULL){
        cout<<"List is empty, cant traverse"<<endl;

        return NULL;
    }
    struct Node* current=new Node();
    current=head;
    while(current!=NULL){
        if(current->data->Getappointment().Getyear()==year){
            count++;
        }
        current=current->next;
    }

    struct Node* current2=new Node();
    current2=head;
    Date* arr=new Date[count];
    int count2=0;
    while(current2!=NULL){
        if(current2->data->Getappointment().Getyear()==year){
            arr[count2]=current2->data->Getappointment();
            count2++;
        }
        current2=current2->next;
    }


    return arr;

}
