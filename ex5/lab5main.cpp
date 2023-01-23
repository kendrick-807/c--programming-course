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
	 	Time(){
			 hours = 0;
			 mins = 0;
		 }
        void read(string prompt );
		friend ostream& operator<<(ostream& os, const Time& dt);
		friend bool operator<(const Time t1,const Time t2);
		bool lessThan(Time time1);
        Time subtract(Time time1);
        void display()const;



		Time operator+(Time& b) {
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

			

			

	  Time operator-(const Time time1) {
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

	   Time& operator ++ ()
    	{
            mins++;
			if(mins == 60){
			hours++;
			mins =0;
			}
			if(hours >=24){
			hours = 0;
			}
        return *this;
    	}
		
		Time operator ++ (int)
    	{
			Time temp = *this;
            ++*this;
			if(temp.mins == 60){
				temp.hours+=1;
				temp.mins -=60;
		}
			if(temp.hours >=24){
				temp.hours = 0;
		}
        return temp;
    	}
	 
	  
	




};
void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}

 ostream&operator<< (ostream& os, const Time& dt){

	    os << setw(2) << setfill('0') << dt.hours << ":"
        << setw(2) << setfill('0') << dt.mins << "\n";
        
        return os;
}

bool operator<(Time t1, Time t2){

	if(t1.hours < t2.hours){

    return true;

    }else if(t1.hours == t2.hours){

        if(t1.mins < t2.mins){

            return true;
        }

    }

    return false;
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

    if(mins < time1.mins)
    {
        --hours;
        mins += 60;
    }

    diff.mins = mins - time1.mins;

    
    
    diff.hours = hours-time1.hours;

    return diff;
}


    

void Time::display()const{

    cout << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << mins << "\n";
         

}