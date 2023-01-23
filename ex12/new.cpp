#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UniqueRng {
public:
    UniqueRng(unsigned int min, unsigned int max);
    int operator()();
private:
    // add something here...
    int minimum;
    int maximum;
    vector<int> numbers;
};

//constructor
UniqueRng::UniqueRng(unsigned int min, unsigned int max) {
    minimum = min;
    maximum = max;
}

//generate random numbers
int UniqueRng::operator()() {
    srand((unsigned)time(NULL));
    int number;
    do {
        number = rand() % (maximum - minimum + 1) + minimum;
        //send error message
        if (numbers.size() >= (maximum - minimum + 1)) {
            throw runtime_error("Unable to produce unique random number");
        }
    } while (find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

void test_generator(UniqueRng ur, int count) {
    vector <int> numbers(count);
    cout << "Generating numbers:" << endl;
    try {
        generate(numbers.begin(), numbers.end(), ur);
    }
    catch (runtime_error& e) {
        //print error message
        cout << "Exception: " << e.what() << endl;
    }
    //find amount of generated numbers
    for (int i = 0;i < numbers.size();i++) {
        if (numbers[i] == NULL) {
            cout << "Tried to generate " << count << " random numbers.Got only " << i << endl;
            break;
        }
    }
    //print numbers
    for (int i = 0;i < numbers.size();i++) {
        if (numbers[i] != NULL) {
            cout << numbers[i] << endl;
        }
    }
    cout << "End of generator" << endl;
    //clear vecctor
    vector <int>().swap(numbers);
}

int main(void) {
    UniqueRng randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

