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
    UniqueRng(unsigned int min, unsigned int max);
    int operator()();

private:
    // add something here...
    int min;
    int max;
    vector <int> nums;
};


UniqueRng::UniqueRng(unsigned int mins,unsigned int maxs): min(mins),max(maxs){}


int UniqueRng::operator()() { 
    int number;
   
    do {
    
    number = rand() % ((max - min) + 1) + min;
    if (nums.size() >= (max - min+ 1)) {
            
        throw runtime_error("Unable to produce unique random number");
    }

} while(find(nums.begin(), nums.end(), number) != nums.end()); 
    nums.push_back(number);
    return number;

}


void test_generator(UniqueRng ur, int count);



void test_generator(UniqueRng ur, int count){
    
    vector<int> dv(count);
    cout << "Generating numbers:" << endl;
    
 try { 

     generate(dv.begin(),dv.end(),ur);
   
    
}   catch (std::runtime_error&e) {
        cout << "Exception: " << e.what() << endl;
       
        for(int i = 0; i < dv.size(); ++i){
        

            if(dv[i] == NULL){

                cout  << "Unable to produce unique random number Tried to generate " << count << " random numbers. Got only " << i << endl;
                break;
            }
           
            
        }
        
    }

    

    for(int i= 0; i < dv.size(); ++i){
          

         if(dv[i] != NULL){
            cout << dv[i] << endl;
        }
            
         
        
    }

    cout << "End of generator" << endl;
    
}


int main(void) {
     srand(time(NULL));
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