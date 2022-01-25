#include "Date.h"
#include <string>
#include <iostream>
using namespace std;
Date::Date(){


}
Date::~Date()
{
    //dtor
}
bool operator== ( Date a, Date b){

    if(a.Getday()==b.Getday()){
        if(a.Getmonth()==b.Getmonth()){
            if(a.Getyear()==b.Getyear()){
                return true;
            }
            return false;
        }
        return false;
    }
    else{

        return false;
    }

}
bool operator>= (Date &a, Date &b){
    if(a.Getyear()>b.Getyear()){
        return true;

    }
    else if(a.Getyear()==b.Getyear()){
        if(a.Getmonth()>b.Getmonth()){
            return true;
        }
        else if(a.Getmonth()==b.Getmonth()){
            if(a.Getday()>=b.Getday()){

                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }

    }
    else{
        return false;
    }
}

bool operator<= (Date &a, Date &b){
    if(a==b){
        return true;
    }
    if((a>=b)==false){
        return true;
    }
    else{
        return false;
    }
}
bool operator!= (Date &a, Date &b){
    if(a==b){
        return false;
    }
    else{
        return true;
    }

}
bool operator> (Date a, Date b){
    if(a.Getyear()>b.Getyear()){
        return true;

    }
    else if(a.Getyear()==b.Getyear()){
        if(a.Getmonth()>b.Getmonth()){
            return true;
        }
        else if(a.Getmonth()==b.Getmonth()){
            if(a.Getday()>b.Getday()){

                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }

    }
    else{
        return false;
    }
}
bool operator< (Date a, Date b){
    if(a==b){
        return false;
    }
    if((a>=b)==false){
        return true;
    }
    else{
        return false;
    }
}
