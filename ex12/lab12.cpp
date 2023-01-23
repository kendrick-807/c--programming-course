
#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;



inline void error(const string& s)
{
    throw runtime_error(s);
}


class UniqueRng {
public:
    UniqueRng(): nums() {srand(time(NULL));}
    UniqueRng(unsigned int mins, unsigned int maxs);
    int operator()();
  
private:
    int min;
    int max;
    vector<int> nums;
};

UniqueRng::UniqueRng(unsigned int mins,unsigned int maxs): min(mins),max(maxs){}


int UniqueRng::operator()() { 
    int number;
    do {

    number = rand() % ((max - min) + 1) + min;

} while(find(nums.begin(), nums.end(), number) != nums.end()); 
    nums.push_back(number);
    return number;

}



void test_generator(UniqueRng ur, int count){
    int size = ur.max - ur.min;
    vector<int> dv(10);
   
    //  generate(dv.begin(),dv.end(),ur);
    // cout << "Generating numbers:" << endl;
    
    // for(auto &t : dv){
    //     cout << t;
    // }
    try {    
    generate(dv.begin(),dv.end(),ur);
    for (auto &t : dv){
        cout << t << endl;
    }
    } catch (std::runtime_error&e) {
        cout << "Index out of range " << endl;
}
  


}


int main(void) {
     srand(time(NULL));
    UniqueRng randGen(5, 13);

    test_generator(randGen, 9);
    // test_generator(randGen, 9);
    // test_generator(randGen, 13);

    // UniqueRng randGen2(1, 35);
    // test_generator(randGen2, 7);
    // test_generator(randGen2, 7);
    // test_generator(randGen2, 7);
    // test_generator(randGen2, 70);

    return 0;
}

