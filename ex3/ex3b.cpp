#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>

using namespace std;

void backwards(vector<string>&array);

void backwards(vector<string>&array) {

    int n = array.size();

    

    for (int i=0;i<n;++i) {

        reverse(array[i].begin(),array[i].end());



    }

    sort(array.begin(),array.end(),greater<string>());

}

int main()
{
    vector<string> array;
    string str;
    string stop = "stop";


    int size = 0;

    cout << "Enter string, type stop to terminate the program\n";

    while (1) {

        
        cin >> str;


        if (str.compare(stop) == 0) {

            break;
            

        }

        array.push_back(str);




        size++;



    }
    cout << "Original array is:\n";
    for (int i = 0; i < size; i++) {


        cout << array[i] << '\n';

    }

    backwards(array);


    cout << "Modified array is:\n";

    for (int i = 0; i < size; i++) {


        cout << array[i] << '\n';

    }











}