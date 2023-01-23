#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include "Time.h"

using namespace std;

void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}

int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1<time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
	}
	cout << "Duration was " << duration << endl;

	vector<Time> tv(5); 
	for(auto &t : tv) {
		t.read("Enter time:");
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

			

void Time::read(string prompt){

    cout << endl << prompt << "\n" ;

    cin >> hours;
    cin >> mins;
    
    while(hours >=24 || mins >=60 || hours < 0 || mins < 0){

        cout << "Invalid date command entered\n";
        cout << endl << prompt << "\n" ;
        cin >> hours;
        cin >> mins;

    }


}
	Time Time::operator+(Time& b) {
			Time add;

			add.hours = hours + b.hours;
			add.mins = mins + b.mins;

			if (add.mins >= 60) {

				add.hours++;
				add.mins = add.mins - 60;
			}

			if (add.hours >= 24 ) {

				add.hours = add.hours - 24;
			}

			

			return add;
		}
			

			

	 Time Time::operator-(const Time time1) {
        	Time diff;

			diff.hours = this->hours - time1.hours;
		    
			diff.mins = this->mins - time1.mins;
			if(mins < time1.mins)
    		{
        		--diff.hours;
        		diff.mins = 60 + diff.mins;
    		}

    

    		
    		return diff;
      }

Time& Time::operator++() {

	++mins; 

	
	if (mins >= 60) {
		mins -= 60;
		hours++;
	}

	
	return *this;
}

Time Time::operator++(int) {

	Time time = *this; 
	++mins; 

	if (mins >= 60) {
		mins -= 60;
		hours++;
	}

	
	return time;
}

	 
	  
	




Time::Time(int hrs, int mmins){ 
	hours = hrs; 
	mins = mmins;
}

 ostream&operator<< (ostream& os, const Time& dt){

	    os << setw(2) << setfill('0') << dt.hours << ":"
        << setw(2) << setfill('0') << dt.mins << "\n";
        
        return os;
}

istream& operator>>(istream& in, Time& dt){

	in >> dt.hours >> dt.mins;

	return in;
}

bool Time::operator<(Time t1)const{

	if(t1.hours > hours){

    return true;

    }else if(t1.hours == hours){

        if(t1.mins > mins){

            return true;
        }

    }

    return false;
}
bool Time::operator>(Time t1)const{

	if(t1.hours < hours){

    return true;

    }else if(t1.hours == hours){

        if(t1.mins < mins){

            return true;
        }

    }

    return false;
}
bool Time::operator==(const Time t1) const {

	return t1.hours == hours && t1.mins == mins; 
}
bool Time::lessThan(Time time1){

    if(hours < time1.hours){

    return true;

    }else if(hours == time1.hours){

        if(mins < time1.mins){

            return true;
        }

    }

    return false;


}

Time Time::subtract(Time time1){

    Time diff;

	diff.hours = this->hours - time1.hours;
		    
	diff.mins = this->mins - time1.mins;
	if(mins < time1.mins)
    {
        --diff.hours;
        diff.mins = 60 + diff.mins;
    }

    

    		
    return diff;
}


    

void Time::display()const{

    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << mins << "\n";
         

}
