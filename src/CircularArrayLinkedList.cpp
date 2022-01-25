#include "CircularArrayLinkedList.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
CircularArrayLinkedList::CircularArrayLinkedList()
{
    //ctor
}

CircularArrayLinkedList::~CircularArrayLinkedList()
{
    //dtor
}
void CircularArrayLinkedList::initializeList(){
    for(int i=0;i<19;i++){
        node[i].info=NULL;
        node[i].next=i+1;
    }
    node[19].info=NULL;
    node[19].next=0;

}
void CircularArrayLinkedList::setAvail(){
    for(int i=0;i<20;i++){
        if(node[i].info==NULL){
            avail=i;
            return;
        }

    }


}
void CircularArrayLinkedList::insertEmp(TemporaryEmployee* emp){
    node[avail].info=emp;
    setAvail();
    currentsize++;


}

void CircularArrayLinkedList::deleteEmp(int id){
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL &&node[i].info->Getid()==id){
            node[i].info=NULL;

            setAvail();
            currentsize--;
            return;
        }
    }

        cout<<"No such employee exists"<<endl;
        return;


}
void CircularArrayLinkedList::updateEmp(int id,string title, float salary){
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL && node[i].info->Getid()==id){
            node[i].info->Setsalary(salary);
            node[i].info->Settitle(title);
            break;
        }
    }


}
void CircularArrayLinkedList::traversePrint(){
    if(node[0].info==NULL){
        cout<<"List empty, can't traverse"<<endl;
        return;
    }
    else{
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL){
           cout<<node[i].info;
        }
    }
    }

}
void CircularArrayLinkedList::printEmp(int id){
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL && node[i].info->Getid()==id){
            cout<<node[i].info<<endl;
            break;
        }
    }


}
bool CircularArrayLinkedList::empExists(int id){
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL && node[i].info->Getid()==id){
            return true;
        }
    }
    return false;
}
void CircularArrayLinkedList::sortList(){
    bool flag=false;
    /* Checking for empty list */
    for(int k=0;k<20;k++){
        if(node[k].info!=NULL){
            flag=true;
        }
    }
    if(flag==false){
        return;
    }
    int arr[currentsize];
    TemporaryEmployee* emp[currentsize];
    int count1=0;
    for(int i=0;i<20;i++){
        if(node[i].info!=NULL){//burdaki eşit değildiri null ile değiştir

            arr[count1]=node[i].info->Getid();//info->Getid
            emp[count1]=node[i].info;
            count1++;
        }
    }
    //cout<<"Before sort"<<endl;


    sort(arr,arr+currentsize);
    int count2=0;
    /*cout<<"\nSorted list is: "<<endl;
    for(int i=0;i<currentsize;i++){
        cout<<arr[i]<<" ";
    }*/
    for(int i=0;i<currentsize;i++){
        for(int k=0;k<currentsize;k++){
            if(emp[k]->Getid()==arr[i]){
                node[i].info=emp[k];
            }
        }
    }


    for(int i=currentsize;i<20;i++){
        node[i].info=NULL;

    }




}
