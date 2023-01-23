#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;


void printsame(const vector<int> &v,string name){
    cout << name << ":" << '\n';
    int i=1;

    for(int t : v) {
		cout << '#' << i << ": " << t << '\n';
        ++i;

	}
    

}
bool comp(int a, int b)
{
    return a < b;
}

class Lotto { 
public:
    Lotto(): nums() {srand(time(NULL));}
    int operator()();
	Lotto(int maxs, int mins){
        max = maxs;
        min = mins;
    }
private:
    vector<int> nums;
    int max;
    int min;
   

};




int Lotto::operator()() { 
    int number;
    do {

    number = rand() % (max - min) + 1;

} while(find(nums.begin(), nums.end(), number) != nums.end()); 
    nums.push_back(number);
    return number;

}

int main(void) {
    vector<int> lottov(7);
    vector<int> vlottov(6);
    vector<int> eujpv(5);
    vector<int> intersect1,intersect2;
    char selection = 'y';

    Lotto lottos(1,40);
    Lotto lotto2(1,48);
    Lotto lotto3(1,50);

    auto print = [](const int& n) { std::cout << " " << n; };


    while (selection != 'n') {

        srand(time(NULL));

        generate(lottov.begin(), lottov.end(), lottos);
        generate(vlottov.begin(), vlottov.end(), lotto2);
        generate(eujpv.begin(), eujpv.end(), lotto3);


        cout << "Lotto:";

        for_each(lottov.begin(), lottov.end(), print);
        cout << endl;

        cout << "Viking Lotto:";
        for_each(vlottov.begin(), vlottov.end(), print);
        cout << endl;

        sort(lottov.begin(), lottov.end());
        sort(vlottov.begin(), vlottov.end());

        std::set_intersection(lottov.begin(), lottov.end(),
            vlottov.begin(), vlottov.end(),
            std::back_inserter(intersect1));

        cout << "Matching numbers:\n";

        int j = 1;
        for_each(intersect1.begin(), intersect1.end(), [&j](int n) {
           
            std::cout << '#' << j << ": " << n << '\n';
            j++;
            });

        cout << "Eurojackport:";
        for_each(eujpv.begin(), eujpv.end(), print);
        cout << endl;

        sort(eujpv.begin(), eujpv.end());

        std::set_intersection(intersect1.begin(), intersect1.end(),
            eujpv.begin(), eujpv.end(),
            std::back_inserter(intersect2));

        cout << "Matching numbers in three sets :\n";

        int i = 1;
        for_each(intersect2.begin(), intersect2.end(),[&i](int n) {
            std::cout << '#' << i << ": " << n << '\n';
            i++;
            });

        cout << "Want to play again? (y/n)";

        cin >> selection;
        cout << endl;
        
        intersect1.clear();
        intersect2.clear();

    }


    

}
    


