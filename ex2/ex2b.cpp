#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>



using namespace std;

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



    cout << "Displaying all strings:\n";

    for (int i = 0; i < size; i++) {

        
        cout << array[i] << '\n';

    }


    auto it = max_element(array.begin(), array.end(),
        [](const auto& a, const auto& b) {
            return a.size() < b.size();
            
        });
   

    int len = INT_MIN;
    int N = array.size();


    for (int i = 0; i < N; i++) {

  
        int l = array[i].size();


        if (len < l) {

            len = l;
        }
    }

    

    cout << "Longest string is: " << * it << '\n';
    cout << "String length is: " << len << '\n';


    return 0;
    







}