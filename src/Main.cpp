#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>
#include "Employee.h"
using namespace std;
#include <string>
#include "TemporaryEmployee.h"
#include "PermanentEmployee.h"
#include "CircularArrayLinkedList.h"
#include "DoubleDynamicLinkedList.h"
#include "Date.h"
bool comp1(Date &a, Date &b){
    return a<b;
}
bool comp2(Date &a, Date &b){
    return a>b;
}
void sortByDate(Date a[], int size){
    //cout<<"Entered sort by date"<<endl;
    int i,j=0;
    Date temp;
    /*for(int k=0;k<size;k++){
        cout<<a[k].Getday()<<"."<<a[k].Getmonth()<<"."<<a[k].Getyear()<<endl;
    }*/
    for(i = 0; i<size; i++) {
    for(j = i+1; j<size; j++)
   {
      if(a[j] < a[i]) {
         //cout<<a[j].Getday()<<"."<<a[j].Getmonth()<<"."<<a[j].Getyear()<<"is less than "<<a[i].Getday()<<"."<<a[i].Getmonth()<<"."<<a[i].Getyear()<<endl;
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }

}
//sort(dates,dates+size,comp1);
}
void sortByDateDescending(Date a[], int size){
    //cout<<"Entered sort by date descending"<<endl;
    int i,j=0;
    Date temp;
    for(int k=0;k<size;k++){
        //cout<<a[k].Getday()<<"."<<a[k].Getmonth()<<"."<<a[k].Getyear()<<endl;
    }
    for(i = 0; i<size; i++) {
    for(j = i+1; j<size; j++)
   {
      if(a[j] > a[i]) {
         //cout<<a[j].Getday()<<"."<<a[j].Getmonth()<<"."<<a[j].Getyear()<<"is bigger than "<<a[i].Getday()<<"."<<a[i].Getmonth()<<"."<<a[i].Getyear()<<endl;
         temp = a[i];
         a[i] = a[j];
         a[j] = temp;
      }
   }



    //sort(dates,dates+size,comp2);
}
}

int main()
{
    cout<<"___Employee Recording System___"<<endl;
    cout<<"Please select for the following Menu Operation:"<<endl;
    cout<<"1) Appointment of a new employee"<<endl;
    cout<<"2) Appointment of a transferred employee"<<endl;
    cout<<"3) Updating the title and salary coefficient of an employee"<<endl;
    cout<<"4) Deletion of an employee"<<endl;
    cout<<"5) Listing the information of an employee"<<endl;
    cout<<"6) Listing employees ordered by employee number"<<endl;
    cout<<"7) Listing employees ordered by appointment date"<<endl;
    cout<<"8) Listing employees appointed after a certain date"<<endl;
    cout<<"9) Listing employees assigned in a given year"<<endl;
    cout<<"10) Listing employees born before a certain date"<<endl;
    cout<<"11) Listing employees born in a particular month"<<endl;
    cout<<"12) Listing the information of the last assigned employee with a given title"<<endl;


    CircularArrayLinkedList templist;
    DoubleDynamicLinkedList permaemplist;
    int currentsizetemp=0;
    int currentsizepermaemp=0;
    int option=-1;
    templist.initializeList();
    while(option!=0){
        //permaemplist.traverseList();
        //templist.traversePrint();
        cin>>option;
        if(option==1){
            cout<<"Option 1 chosen"<<endl;
            string name;
            string surname;
            string birthday;
            string appointmentday;
            int id;
            string title;
            float salary;
            int type;
            int bdate;
            int bmonth;
            int byear;
            int appdate;
            int appmonth;
            int appyear;
            cout<<"Enter your id: "<<endl;
            cin>>id;

            //code to check if the id exists, if it exists, dont add employee
            if(templist.empExists(id)||permaemplist.searchEmp(id)==true){
                cout<<"This id already exists, cant add new employee."<<endl;
            }
            else{

            cout<<"Type the employee type: "<<endl;
            cin>>type;
            cin.ignore();
            cout<<"Enter your name: "<<endl;
            //cin>>name;
            getline(cin,name);

            cout<<"Enter your surname: "<<endl;
            //cin>>surname;

            getline(cin,surname);

            cout<<"Enter your title: "<<endl;

            getline(cin,title);
            //cin>>title;

            cout<<"Enter your salary: "<<endl;

            cin>>salary;

            cout<<"Enter your birth date: "<<endl;
            cin>>birthday;

            cout<<"Enter your appointment date: "<<endl;
            cin>>appointmentday;


            bdate=stoi(birthday.substr(0,2));
            bmonth=stoi(birthday.substr(3,4));
            byear=stoi(birthday.substr(6,9));

            appdate=stoi(appointmentday.substr(0,2));
            appmonth=stoi(appointmentday.substr(3,4));
            appyear=stoi(appointmentday.substr(6,9));


            if(type==0){
               //Temporary Employee
               TemporaryEmployee* a=new TemporaryEmployee(id, name, surname, title, salary,bdate,bmonth,byear,appdate,appmonth,appyear,0);
               templist.insertEmp(a);
               currentsizetemp++;
               templist.sortList();
               //cout<<a<<endl;
               //code to add to list
            }
            else if(type==1){
               //Permanent Employee
               PermanentEmployee* a=new PermanentEmployee(id, name, surname, title, salary,bdate,bmonth,byear,appdate,appmonth,appyear,0);
                permaemplist.insertAtFront(a);
                currentsizepermaemp++;
                permaemplist.sortList();
               //cout<<a<<endl;
               //code to add to list
            }

            cout<<"Added new employee successfully"<<endl;
            //cout<<a<<endl;
            }
        }
        else if(option==2){
            cout<<"Option 2 chosen"<<endl;

            string name;
            string surname;
            int id;
            string title;
            string birthday;
            string appointmentday;
            float salary;
            int type;
            int bdate;
            int bmonth;
            int byear;
            int appdate;
            int appmonth;
            int appyear;
            int servicelength;
            cout<<"Enter your id: "<<endl;
            cin>>id;

            //code to check if the id exists, if it exists, dont add employee
            if(templist.empExists(id)||permaemplist.searchEmp(id)==true){
                cout<<"This id already exists, cant add new employee."<<endl;
            }
            else{
            cout<<"Type the employee type: "<<endl;
            cin>>type;
            cin.ignore();
            cout<<"Enter your name: "<<endl;
            //cin>>name;
            getline(cin,name);
            cout<<"Enter your surname: "<<endl;
            //cin>>surname;
            getline(cin,surname);
            cout<<"Enter your title: "<<endl;
            //cin>>title;
            getline(cin,title);
            cout<<"Enter your salary: "<<endl;
            cin>>salary;
            cout<<"Enter your birth date: "<<endl;
            cin>>birthday;
            cout<<"Enter your appointment date: "<<endl;
            cin>>appointmentday;

            cout<<"Enter your service length: "<<endl;
            cin>>servicelength;

            bdate=stoi(birthday.substr(0,2));
            bmonth=stoi(birthday.substr(3,4));
            byear=stoi(birthday.substr(6,9));

            appdate=stoi(appointmentday.substr(0,2));
            appmonth=stoi(appointmentday.substr(3,4));
            appyear=stoi(appointmentday.substr(6,9));
            if(type==0){
               //Temporary Employee
               TemporaryEmployee* a=new TemporaryEmployee(id, name, surname, title, salary,bdate,bmonth,byear,appdate,appmonth,appyear,servicelength);
               templist.insertEmp(a);
               currentsizetemp++;
               templist.sortList();
               //cout<<a<<endl;
               //code to add to list
            }
            else if(type==1){
               //Permanent Employee
               PermanentEmployee* a=new PermanentEmployee(id, name, surname, title, salary,bdate,bmonth,byear,appdate,appmonth,appyear,servicelength);
               permaemplist.insertAtFront(a);
               currentsizepermaemp++;
               permaemplist.sortList();

            }

            cout<<"Added transferred employee successfully"<<endl;
            //cout<<a<<endl;
            }
        }
        else if(option==3){ //updating title and salary
            cout<<"Option 3 chosen"<<endl;
            int id;
            string newTitle;
            float newSalary;
            bool flag1=false;
            bool flag2=false;
            cout<<"Enter the id of the employee you want to edit"<<endl;
            cin>>id;
            if(templist.empExists(id)){
                cout<<"Enter new title"<<endl;
                cin.ignore();
                getline(cin,newTitle);
                //cin>>newTitle;
                cout<<"Enter new salary"<<endl;
                cin>>newSalary;
                templist.updateEmp(id,newTitle,newSalary);
                flag1=true;
                cout<<"Employee edited successfully"<<endl;
            }
            else if(permaemplist.searchEmp(id)==true){
                cout<<"Enter new title"<<endl;
                cin.ignore();
                getline(cin,newTitle);
                //cin>>newTitle;
                cout<<"Enter new salary"<<endl;
                cin>>newSalary;
                permaemplist.editEmp(id,newTitle,newSalary);
                cout<<"Employee edited successfully"<<endl;
                flag2=true;
            }

            if(flag1==false&&flag2==false){
                cout<<"Couldn't find the employee with the given id"<<endl;
            }
        }
        else if(option==4){//deletion of an employee
            cout<<"Option 4 chosen"<<endl;
            int id;
            bool flag1=false;
            bool flag2=false;
            cout<<"Enter the id of the employee you want to delete"<<endl;
            cin>>id;
            //search temporary employee for the id
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){

                }
                else if(templist.node[i].info->Getid()==id){
                    templist.deleteEmp(id);
                    currentsizetemp--;

                    flag1=true;
                }
            }

                if(permaemplist.searchEmp(id)==true){
                    flag2=true;
                    permaemplist.removeNode(permaemplist.returnEmp(id));
                    currentsizepermaemp--;
                }
            cout<<"Deleted successfully"<<endl;


            if(flag1==false&&flag2==false){
                cout<<"Couldn't find the employee with the given id"<<endl;
            }
        }
        else if(option==5){//Listing information of employee
            cout<<"Option 5 chosen"<<endl;
            int id;
            bool flag1=false;
            bool flag2=false;
            cout<<"Enter the id of the employee you want to get information"<<endl;
            cin>>id;
            //search temporary employee for the id
            if(templist.empExists(id)==true){
                templist.printEmp(id);
                flag1=true;

            }
            else if(permaemplist.searchEmp(id)==true){
                permaemplist.searchAndPrint(id);
                flag2=true;
            }

            if(flag1==false&&flag2==false){
                cout<<"Couldn't find the employee with the given id"<<endl;
            }

        }
        else if(option==6){
            cout<<"Option 6 chosen"<<endl;
            int sizeOfArr=currentsizepermaemp+currentsizetemp;

            if(sizeOfArr==0){
                cout<<"There is no employee in the system"<<endl;
            }
            else{

            int ids[sizeOfArr];
            int count=0;
            //iterate temporary employee list and insert their ids to the array
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info!=NULL){

                    ids[count]=templist.node[i].info->Getid();
                    count++;
                }
            }


            //continue from the end of the temporary employee index and iterate permanent employees and insert the ids to array
            int* temparr;
            temparr=permaemplist.returnIDs(currentsizepermaemp);
            int count2=0;
            if(temparr==NULL){

            }
            else{
            for(int i=currentsizetemp;i<currentsizepermaemp+currentsizetemp;i++){

                ids[i]=temparr[count2];
                count2++;
            }
            }
            //sort the array ids
            sort(ids, ids+sizeOfArr);



            //for every index search and print the employee
            for(int i=0;i<sizeOfArr;i++){
                if(templist.empExists(ids[i])){
                    templist.printEmp(ids[i]);
                }
                else{
                    permaemplist.searchAndPrint(ids[i]);
                }
            }
            delete[] temparr;
            }
        }
        else if(option==7){
            cout<<"Option 7 chosen"<<endl;
            int sizeOfArr=currentsizepermaemp+currentsizetemp;
            Date dates[sizeOfArr];
            //iterate temporary employee list and insert their appointment dates to the array
            for(int i=0;i<currentsizetemp;i++){
                if(templist.node[i].info==NULL){
                }
                dates[i]=templist.node[i].info->Getappointment();
            }
            //continue from the end of the temporary employee index and iterate permanent employees and insert the appointment dates to array
            Date* temparr;
            temparr=permaemplist.returnDates(currentsizepermaemp);
            int count=0;
            for(int i=currentsizetemp;i<currentsizepermaemp+currentsizetemp;i++){

                dates[i]=temparr[count];
                count++;
            }
            //sort the array ids
            sortByDate(dates,sizeOfArr);
            //check the sorted array

            //for every index search and print the employee
            for(int i=0;i<sizeOfArr;i++){
                for(int k=0;k<20;k++){
                if(templist.node[k].info!=NULL && templist.node[k].info->Getappointment()==dates[i]){
                    cout<<templist.node[k].info<<endl;
                }
                }
                permaemplist.traverseListAppDate(dates[i]);
            }
        }
        else if(option==8){
            cout<<"Option 8 chosen"<<endl;
            string date;
            int appday;
            int appmonth;
            int appyear;
            cout<<"Enter the date"<<endl;
            cin>>date;
            //take the date as input and split it
            appday=stoi(date.substr(0,2));
            appmonth=stoi(date.substr(3,4));
            appyear=stoi(date.substr(6,9));
            Date a(appday,appmonth,appyear);

            //iterate for temporary employee list and if the appointment date is > than the given date, add it to the array
            int count=0;
            //to find out the array size
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getappointment()>a){

                    count++;
                }
            }
            //count gives the number of temporary employee dates that are bigger than the input
            int permSize=permaemplist.returnDateBiggerlength(a);

            Date dates[count+permSize];

            int count2=0;
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getappointment()>a){
                    dates[count2]=templist.node[i].info->Getappointment();

                    count2++;
                }
            }

            //iterate for permanent employee list and if the appointment date is > than the given date, add it to the array
            Date* temparr;
            temparr=permaemplist.returnBiggerDates(a);
            int count3=0;

            for(int i=count2;i<count2+permSize;i++){

                dates[i]=temparr[count3];
                count3++;
            }


            //sort the array
            sortByDateDescending(dates,count+permSize);
            //for each index search and print the employee

            for(int i=0;i<count+permSize;i++){
                for(int k=0;k<20;k++){
                    if(templist.node[k].info==NULL){

                    }
                    else if(templist.node[k].info->Getappointment()==dates[i]){
                        cout<<templist.node[k].info<<endl;
                    }
                }
                permaemplist.traverseListAppDate(dates[i]);

            }
            delete[] temparr;
        }
        else if(option==9){
            cout<<"Option 9 chosen"<<endl;
            int year;
            cout<<"Enter the year"<<endl;
            cin>>year;
            int count=0;
            //to find out the array size
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getappointment().Getyear()==year){

                    count++;
                }
            }
            //count gives the number of temporary employee dates that are bigger than the input
            int permSize=permaemplist.returnEqualYearlength(year);
            Date dates[count+permSize];
            int count2=0;
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getappointment().Getyear()==year){
                    dates[count2]=templist.node[i].info->Getappointment();
                    count2++;
                }
            }
            //iterate for permanent employee list and if the appointment date is > than the given date, add it to the array
            Date* temparr;
            temparr=permaemplist.returnEqualYearDates(year);

            int count3=0;
            for(int i=count2;i<count+permSize;i++){
                dates[i]=temparr[count3];
                count3++;
            }


            //sort the array

            sortByDate(dates,count+permSize);

            //for each index search and print the employee
            for(int i=0;i<count+permSize;i++){
                for(int k=0;k<20;k++){
                    if(templist.node[k].info==NULL){

                    }
                    else if(templist.node[k].info->Getappointment()==dates[i]){
                        cout<<templist.node[k].info<<endl;
                    }
                }
                permaemplist.traverseListAppDate(dates[i]);

            }
            delete[] temparr;


        }
        else if(option==10){
            cout<<"Option 10 chosen"<<endl;
            string birthdate;
            int bday;
            int bmonth;
            int byear;
            cout<<"Enter the date"<<endl;
            cin>>birthdate;
            bday=stoi(birthdate.substr(0,2));
            bmonth=stoi(birthdate.substr(3,4));
            byear=stoi(birthdate.substr(6,9));
            Date a(bday,bmonth,byear);

            //iterate for temporary employee list and if the appointment date is > than the given date, add it to the array
            int count=0;
            //to find out the array size
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getbirthdate()<a){

                    count++;
                }
            }
            //count gives the number of temporary employee dates that are bigger than the input
            int permSize=permaemplist.returnDateSmallerlength(a);
            int ids[count+permSize];

            int count2=0;
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getbirthdate()<a){
                    ids[count2]=templist.node[i].info->Getid();

                    count2++;
                }
            }
            //iterate for permanent employee list and if the appointment date is > than the given date, add it to the array
            int* temparr;
            temparr=permaemplist.returnSmallerBDates(a);
            int count3=0;
            int sizeOfArr=count+permSize;
            for(int i=count2;i<count2+permSize;i++){

                ids[i]=temparr[count3];
                count3++;
            }


            //sort the array

            sort(ids,ids+count+permSize);
            //for each index search and print the employee


            for(int i=0;i<sizeOfArr;i++){
                if(templist.empExists(ids[i])){
                    templist.printEmp(ids[i]);
                }
                else{
                    permaemplist.searchAndPrint(ids[i]);
                }
            }
            delete[] temparr;

        }
        else if(option==11){
            cout<<"Option 11 chosen"<<endl;
            int month;
            cout<<"Enter the month"<<endl;
            cin>>month;
            int count=0;


            //to find out the array size
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getbirthdate().Getmonth()==month){

                    count++;
                }
            }
            //count represents the temporary employee number which is born in this month
            //sizeofTempArr will represent the permanent employee number which is born in this month
            int sizeOfTempArr=permaemplist.returnMonthIDlength(month);

            int sizeOfArr=count+sizeOfTempArr;
            int ids[sizeOfArr];

            int count2=0;

            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Getbirthdate().Getmonth()==month){
                    ids[count2]=templist.node[i].info->Getid();
                    count2++;
                }
            }
            //for permanent employee
            int* temparr;
            temparr=permaemplist.returnMonthIDs(month);
            int count3=0;

            for(int i=count2;i<sizeOfArr;i++){

                    ids[i]=temparr[count3];
                    count3++;

            }
            sort(ids, ids+sizeOfArr);

            for(int i=0;i<sizeOfArr;i++){
                if(templist.empExists(ids[i])){
                    templist.printEmp(ids[i]);
                }
                else{
                    permaemplist.searchAndPrint(ids[i]);
                }
            }
            delete[] temparr;


        }
        else if(option==12){
            cout<<"Option 12 chosen"<<endl;
            string title;
            int tempnum=0;
            Date tempfinal;
            Date permfinal;
            cin.ignore();
            cout<<"Enter the title"<<endl;
            getline(cin,title);
            //cin>>title;

            int count=0;
            //to find out the array size
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Gettitle()==title){

                    count++;
                }
            }
            //count gives the number of temporary employee dates that are bigger than the input
            int permSize=permaemplist.returnEqualTitlelength(title);
            Date dates[count+permSize];
            int count2=0;
            for(int i=0;i<20;i++){
                if(templist.node[i].info==NULL){
                }
                else if(templist.node[i].info->Gettitle()==title){
                    dates[count2]=templist.node[i].info->Getappointment();
                    count2++;
                }
            }
            //iterate for permanent employee list and if the appointment date is > than the given date, add it to the array
            Date* temparr;
            temparr=permaemplist.returnEqualTitleDates(title);
            int count3=0;
            for(int i=count2;i<count+permSize;i++){
                dates[i]=temparr[count3];
                count3++;
            }


            //sort the array

            sortByDateDescending(dates,count+permSize);
            //for each index search and print the employee
            cout<<"Last assigned employee with the "<<title<<" is:"<<endl;
            for(int i=0;i<1;i++){
                for(int k=0;k<20;k++){
                    if(templist.node[k].info==NULL){

                    }
                    else if(templist.node[k].info->Getappointment()==dates[i]){
                        cout<<templist.node[k].info<<endl;
                    }
                }
                permaemplist.traverseListAppDate(dates[i]);

            }
            delete[] temparr;


        }







    }

    return 0;
}
