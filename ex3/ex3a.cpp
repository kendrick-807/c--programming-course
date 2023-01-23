
#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 

using namespace std;

int main()
{

    vector<double> array;
    double number = 0;
    int sizes = 0;

    cout << "Enter number, negative number will stop the program\n";

    while (1) {

        

        cin >> number;

        if (number < 0) {
            break;
        }
        else {

            array.push_back(number);
            number = 0;
            sizes++;
        }



    }
    


    sort(begin(array),end(array));

    cout << "Displaying array in accending order\n";

    for(int i=0; i<sizes; ++i){

        cout << setprecision(3) << array[i] << '\n';

    }

    return 0;

}