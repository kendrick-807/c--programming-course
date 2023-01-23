#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

class Time {
    private:
        int hours;
        int mins;
    public:
        void read(string prompt );
        bool lessThan(Time time1);
        Time subtract(Time time1);
        void display()const;


};



        




int main() {
	Time time1, time2, duration;

	time1.read("Enter time 1");
	time2.read("Enter time 2");
	if (time1.lessThan(time2)) {
		duration = time2.subtract(time1);
		cout << "Starting time was ";
		time1.display();
	} else {
		duration = time1.subtract(time2);
		cout << "Starting time was ";
		time2.display();
	}
	cout << "Duration was ";
	duration.display();

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

Time Time::subtract( Time time1){

    Time diff;

    if(mins < time1.mins)
    {
        --diff.hours;
        diff.mins += 60;
    }

    diff.mins = mins - time1.mins;

    
    
    diff.hours = hours-time1.hours;

    return diff;
}


    

void Time::display()const{

    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << mins << "\n";
         

}