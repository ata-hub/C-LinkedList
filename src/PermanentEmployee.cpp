#include "PermanentEmployee.h"
#include <iostream>
#include "Date.h"
using namespace std;
/*PermanentEmployee::PermanentEmployee(int id, string name, string surname, string title, float salary)
{
    this->id=id;
    this->name=name;
    this->surname=surname;
    this->title=title;
    this->salary=salary;
    cout<<"Permanent employee created"<<endl;


}*/

PermanentEmployee::~PermanentEmployee()
{
    //dtor
}
string PermanentEmployee::printBirthday(Date bday){
    string s;
    string day=to_string(bday.Getday());
    string month=to_string(bday.Getmonth());
    string year=to_string(bday.Getyear());
    s=day +"." + month +"."+year;
    return s;
}
string PermanentEmployee::printAppointment(Date appday){
    string s;
    string day=to_string(appday.Getday());
    string month=to_string(appday.Getmonth());
    string year=to_string(appday.Getyear());
    s=day+"."+ month+"."+year;
    return s;
}

ostream& operator<<(ostream& output, PermanentEmployee* emp){

output<<"ID: "<<emp->Getid()<<"\n"<<"Employee type: "<<emp->getType()<<"\n"<<"Name: "<<emp->Getname()<<"\n"<<"Surname: "<<emp->Getsurname()<<"\n"<<"Title: "<<emp->Gettitle()<<
        "\n"<<"Salary: "<<emp->Getsalary()<<"\n"
        <<"Birth date: "<<emp->printBirthday(emp->Getbirthdate())<<"\n"
        <<"Appointment date :"<<emp->printAppointment(emp->Getappointment())<<"\n"
        <<"Service length: "<<emp->Getservicelength()<<"\n";
return output;

}
