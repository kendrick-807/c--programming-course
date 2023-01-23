#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "Time.h"
#pragma warning(disable : 4996)

using namespace std;

class Day {
public:
    Day();
    bool from_str(const string &s);
    string to_str();
    void dst(int offset);
private:
    int day;
    string month;
    vector<Time> list;
};



int main()
{
    ifstream inputFile("lab6_calendar.txt");

    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string line;
    vector<Day> cal;
    Day day;

    while (getline(inputFile, line)) {
        if (day.from_str(line)) {
            cal.push_back(day);
        }
    }
    cout << "Calendar" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    // DST shift
    for (auto& e : cal) {
        e.dst(1);
    }
    cout << "DST" << endl;

    for (auto& e : cal) {
        cout << e.to_str() << endl;
    }

    cout << "End" << endl;

    return 0;
}

Time::Time(int hours0, int minutes0) :hours(hours0), mins(minutes0) { 
}

void Time::operator()(int h_hours, int m_minutes) {

    hours = h_hours; 
    mins = m_minutes; 
}

int Time::get_hours() {

    return hours; 

}

int Time::get_mins() {

    return mins; 

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

Day::Day() {

}

bool Day::from_str(const string& s) {
    vector <int> pos; 
    int end = 2; 
    int ignore = 0; 
    Time time;
    bool r = false;


    day = 0;
    month.erase();
    vector<Time>().swap(list);

    pos.push_back(s.find(" ")); 

    if (pos[0] != string::npos) { 

        if (s.substr(0, pos[0]) != "Broken") { 

            day = stoi(s.substr(0, pos[0])); 
        }
        else {

            return r; 

        }
    }
    else {

        return r; 

    }

    pos.push_back(s.find(" ",pos[0]+1)); 
    if (pos[1] != string::npos) { 

        if (s.substr(pos[0] + 1, pos[1]) != "Broken") { 

            month = s.substr(pos[0] + 1, pos[1]); 
        }

        else {

            return false;
        }
    }
    else {

        return false; 

    }
    pos.push_back(s.find(" ", pos[1] + 1)); 
     for (int i = 2;pos[i] != string::npos;i++) {
        if (s.substr(pos[i - 1] + 1, pos[i - 1] + 3) != "Br" && s.substr(pos[i] - 2, pos[i]) != "en") { 

            time(stoi(s.substr(pos[i - 1] + 1, pos[i - 1] + 3)), stoi(s.substr(pos[i] - 2, pos[i]))); 

            list.push_back(time);

            r = true; 
        }
        else {
            ignore++; 
        }
        pos.push_back(s.find(" ", pos[i] + 1)); 

        end = i; 

        if (pos[i] == pos[i - 1] + 1) {

            break;

        }
    }

     
    if (s.substr(pos[end - 1] + 1, pos[end - 1] + 3) != "Br" && s.substr(s.length() - 2, s.length()) != "en") {

        list[end - 2 - ignore](stoi(s.substr(pos[end - 1] + 1, pos[end - 1] + 3)), stoi(s.substr(s.length() - 2, s.length())));

        r = true;
    }

    return r; 
}

string Day::to_str() {
 
    string content; 
    content = day + " " + month + " "; 


    for (int i = 0;i < list.size();i++) {
        content += list[i].get_hours();
        content += ":";
        content += list[i].get_mins();
        content += ":";
    }

    return content; 
}

void Day::dst(int offset) {
    Time time1; 
    time1(offset, 0); 


    for (int i = 0;i < list.size();i++) {
        list[i] = list[i] + time1;
    }
}