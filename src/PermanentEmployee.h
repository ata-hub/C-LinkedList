#ifndef PERMANENTEMPLOYEE_H
#define PERMANENTEMPLOYEE_H

#include "Employee.h"
#include <iostream>
#include "Date.h"
using namespace std;

class PermanentEmployee : public Employee
{
    public:
        PermanentEmployee(int Id, string Name, string Surname, string Title, float Salary,int bday,int bmonth, int byear, int appday, int appmonth, int appyear, int Service)
        :id(Id),name(Name),surname(Surname),title(Title),salary(Salary),servicelength(Service),birthdate(bday,bmonth,byear),appointment(appday,appmonth,appyear){}
        virtual ~PermanentEmployee();

        int Getid() { return id; }
        string Getname() { return name; }
        string Getsurname() { return surname; }
        string Gettitle() { return title; }
        void Settitle(string val ) { title = val; }
        void printEmployee(Employee* Employee);
        float Setsalary(float val){salary=val;}
        float Getsalary(){return salary;}
        //int Setservicelength(int val){servicelength=val;}
        int Getservicelength(){return servicelength;}
        Date Getbirthdate(){return birthdate;}
        Date Getappointment(){return appointment;}
        string printBirthday(Date bday);
        string printAppointment(Date appday);


        string getType(){return type;};
        friend ostream &operator<<( ostream &output, PermanentEmployee* emp );

    protected:

    private:
        const string type="Permanent Employee";
        const int id;
        const string name;
        const string surname;
        string title;
        float salary;
        const int servicelength;
        const Date birthdate;
        const Date appointment;
};

#endif // PERMANENTEMPLOYEE_H
