#include <iostream>
#include <cstdlib>

using namespace std;
int mean(int *array, int n);

int main()
{
    int *array;
    int ask = 0;
    int meannum = 0;


    srand (time(NULL));

    cout<< "How many numbers you need?";
    cin >> ask;

    array = new int (ask);

    cout << "The numbers are:\n";

    for(int i = 0 ; i < ask ; ++i){

        array[i]=rand()%100;


        cout << array[i] << '\n';

       

    }

    
    meannum = mean(array,ask);

    cout << "Mean:" << meannum;

    delete(array);

    return 0;
}

int mean(int *array, int n)
{
    int sum = 0;

    for(int i = 0 ; i < n ; ++i){

        sum += array[i];

    }

    return sum/n;


}