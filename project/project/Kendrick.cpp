#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>
#include <fstream>

using namespace std;



class Match {
public:
    Match();
    Match(string H, string A, int h, int a, string c, int w);
    string getLoc() { return loc; }
    string gethTeam() { return hTeam; }
    string getaTeam() { return aTeam; }
    int getWeek() { return week; }
    int getScore() { return hScore + aScore; };
    Match userInput();
    vector<Match> add(vector <Match> add);
    vector<Match> find(vector <Match> find);
    bool checkError(vector <Match> check, Match input);
    vector<Match> printTeam(vector <Match> printTeam);
    vector<Match> printLoc(vector <Match> printTeam);
    void findGoal(vector <Match> find);
    friend istream& operator >> (istream& in, Match& obj);
    friend ostream& operator << (ostream& out, Match& obj);
    Match operator =(const Match& n)
    {
        hTeam = n.hTeam;
        aTeam = n.aTeam;
        hScore = n.hScore;
        aScore = n.aScore;
        loc = n.loc;
        week = n.week;

        return n;
    }

private:
    // add something here...
    string hTeam;
    string aTeam;
    int hScore;
    int aScore;
    string loc;
    int week;



};

Match::Match() {

    hTeam = "-";
    aTeam = "-";
    hScore = 0;
    aScore = 0;
    loc = "-";
    week = 0;
}
Match::Match(string H, string A, int h, int a, string c, int w) : hTeam(H), aTeam(A), hScore(h), aScore(a), loc(c), week(w) {}



Match Match::userInput() {
    string hTeam;
    string aTeam;
    int hScore = 0;
    int aScore = 0;
    string loc;
    int week = 0;
    cout << "Enter the home team name:";
    cin >> hTeam;
    cout << "Enter the away team name:";
    cin >> aTeam;
    cout << "Enter the home team score:";
    cin >> hScore;
    cout << "Enter the away team score:";
    cin >> aScore;
    cout << "Enter the location:";
    cin >> loc;
    cout << "Enter the week number:";
    cin >> week;

    Match newMatch(hTeam, aTeam, hScore, aScore, loc, week);
    return newMatch;
}


vector<Match> Match::add(vector <Match> add) {


    Match newMatch = userInput();



    while (1) {

        if (newMatch.checkError(add, newMatch) == false) {

            cout << "Error!" << endl;
            newMatch = userInput();

        }
        else {
            break;
        }



    }
    add.push_back(newMatch);

    cout << "Match added!" << endl;

    return add;

}


vector<Match> Match::find(vector <Match> find) {
    string location;
    int week = 0;
    bool weekfind = false;

    cout << "Printing the matches:" << endl;
    for (auto t : find) {
        cout << t;
    }
    cout << "Find the match according to its location:";
    cin >> location;
    cout << "Find the match according to its week:";
    cin >> week;
    auto it = find_if(find.begin(), find.end(), [&location](Match& test) {return test.getLoc() == location; });
    auto index = std::distance(find.begin(), it);

    for (int i = 0; i < find.size(); ++i) {

        if (find[i].getWeek() == week && find[i].getLoc() == location) {

            weekfind = true;
            break;
        }
    }
    if (weekfind == true)
    {

        cout << "Match find." << endl;
        cout << find[index] << endl;



        Match newMatch = userInput();

        while (1) {

            if (newMatch.checkError(find, newMatch) == false) {

                cout << "Error!" << endl;
                newMatch = userInput();

            }
            else {
                break;
            }



        }

        find[index] = newMatch;

        for (auto t : find) {

            cout << t << endl;
        }



        cout << "Match corrected!" << endl;

    }
    else {
        cout << "Location not found." << endl;
    }

    return find;
}

vector<Match> Match::printTeam(vector <Match> printTeam) {

    string selection;
    bool matched = false;

    cout << "Please enter the team name:" << endl;
    cin >> selection;



    for (int i = 0; i < printTeam.size(); ++i) {



        if (selection == printTeam[i].getaTeam() || selection == printTeam[i].gethTeam()) {

            cout << printTeam[i];
            matched = true;

        }
        else if (i == printTeam.size() - 1 && selection != printTeam[i].getaTeam() && selection != printTeam[i].getaTeam() && matched == false) {

            cout << "No team found." << endl;

        }

    }

    return printTeam;

}
vector<Match> Match::printLoc(vector <Match> printTeam) {

    string Location;
    bool matched = false;

    cout << "Please enter the location:" << endl;
    cin >> Location;



    for (int i = 0; i < printTeam.size(); ++i) {



        if (Location == printTeam[i].getLoc()) {

            cout << printTeam[i];
            matched = true;

        }
        else if (i == printTeam.size() - 1 && Location != printTeam[i].getLoc() && matched == false) {

            cout << "No team found." << endl;

        }

    }

    return printTeam;

}

bool Match::checkError(vector <Match> check, Match input) {

    for (int i = 0; i < check.size(); ++i) {

        if (check[i].getaTeam() == input.getaTeam() || check[i].gethTeam() == input.gethTeam() || check[i].getaTeam() == input.gethTeam() || check[i].gethTeam() == input.getaTeam()) {

            if (check[i].getWeek() == input.getWeek()) {

                return false;

            }
        }
        if (check[i].getWeek() == input.getWeek() && check[i].getLoc() == input.getLoc()) {

            return false;

        }

        if (input.getaTeam() == input.gethTeam()) {

            return false;
        }

    }

    return true;

}


void Match::findGoal(vector <Match> find) {
   
    
 
        int largest = find[0].getScore();

        for (int i = 0; i < find.size(); i++) {
            if (largest < find[i].getScore()) {
                largest = find[i].getScore();
            }
        }

        cout << "Printing the highest number of goal in a match" << endl;

        for (int i = 0; i < find.size(); i++) {

            if (find[i].getScore() == largest) {

                cout << find[i];
            }
        }
    



}


istream& operator >> (istream& in, Match& obj)
{
    in >> obj.hTeam;
    in >> obj.aTeam;
    in >> obj.hScore;
    in >> obj.aScore;
    in >> obj.loc;
    in >> obj.week;
    return in;
}

ostream& operator << (ostream& out, Match& obj)
{

    out << left << setw(12) << obj.hTeam;
    out << left << setw(12) << obj.aTeam;
    out << left << setw(3) << obj.hScore;
    out << left << setw(5) << obj.aScore;
    out << left << setw(15) << obj.loc;
    out << left << setw(5) << obj.week << endl;
    return out;
}

int main() {

    ifstream inData;
    ofstream outData;
    string fName ;
    string iName;
    Match testing;
    vector <Match> matches;
    int selection = 1;

    cout << "Welcome to the football result program." << endl;

    while (selection != 10) {


        cout << '\n' << "1.Initialize" << '\n';
        cout << "2.Save records to file" << '\n';
        cout << "3.Read records from file" << '\n';
        cout << "4.Add new match" << '\n';
        cout << "5.Make corrections to an existing match" << '\n';
        cout << "6.Print a report of matches where user specified team has played" << '\n';
        cout << "7.Print a report of matches played in a user specified location" << '\n';
        cout << "8.Print all the football matches" << '\n';
        cout << "9.Print the highest number of goal in a match" << '\n';
        cout << "10. Quit the program" << '\n';

        cin >> selection;

        if (selection == 1) {

            matches.clear();

        }
        else if (selection == 2) {

            cout << "Type file name:" << endl;
            cin >> iName;
            outData.open(iName);
            if (!outData) {

                cout << "File doesn't exist!" << endl;
            }
            if (outData.is_open()) {



                for (int i = 0; i < matches.size(); i++) {

                    outData << matches[i];
                }

                cout << '\n' << "File saved!" << endl;
            }
           
           

            outData.close();
            matches.clear();


        }
        else if (selection == 3) {

            cout << "Type file name:" << endl;
            cin >> fName;
            inData.open(fName);
            if (!inData) {

                cout << "File doesn't exist!" << endl;
            }
            if (inData.is_open()) {
                cout << '\n' << "Displaying teams:" << endl;
                while (inData >> testing) {
                    cout << testing;
                    matches.push_back(testing);
                    
                }
           
            


            }
          
            inData.close();
        }
        else if (selection == 4) {

            matches = testing.add(matches);

        }
        else if (selection == 5) {

            matches = testing.find(matches);

        }
        else if (selection == 6) {

            matches = testing.printTeam(matches);

        }
        else if (selection == 7) {

            matches = testing.printLoc(matches);

        }
        else if (selection == 8) {

            for (auto t : matches) {

                cout << t;
            }

        }
        else if (selection == 9) {

            testing.findGoal(matches);

        }
    }








}