#pragma once
#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <iostream>

using namespace std;

class Time {
    friend ostream& operator<<(ostream& os, const Time& dt);
    friend istream& operator>>(istream& in, Time& dt);

    public:
    Time(int hours = 0, int minutes = 0); 	  
        void read(string prompt );
        Time operator+(Time &b);
        Time operator-(const Time time1);
        Time& operator ++ ();
        Time operator ++ (int);
        bool lessThan(Time time1);
        Time subtract(Time time1);
        bool operator==(const Time t1) const;
        bool operator<(const Time t1)const;
        bool operator>(const Time t1) const; 
        void display(void)const;
        int get_hours();
	    int get_mins();
        void operator()(int h_hours, int m_minutes);

    private:
    int hours;
    int mins;
        

       


};


#endif