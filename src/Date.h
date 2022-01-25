#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int a, int b, int c) : day(a),month(b),year(c){}
        virtual ~Date();

         int Getday() { return day; }

         int Getmonth() { return month; }

         int Getyear() { return year; }
        friend bool operator== ( Date a, Date b);
        friend bool operator>= (Date &a, Date &b);
        friend bool operator<= (Date &a, Date &b);
        friend bool operator!= (Date &a, Date &b);
        friend bool operator> (Date a, Date b);
        friend bool operator< (Date a, Date b);


    protected:

    private:
          int day;
          int month;
          int year;
};

#endif // DATE_H
