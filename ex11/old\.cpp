#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;

class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};

class LimitedCounter: public Counter{

public:
	LimitedCounter(int value = 0, int limit = 0);
	void inc(){
	if(intValue >= upLimit){

	}else{

		intValue++;

		}
	};
	void dec(){
	if(intValue <= 0){

	}else{

		intValue--;

		}
	};
	  operator int()
   {
      return intValue;
   }
	;
private:
	int intValue;
	int upLimit;
};

class Observer {
public:
       virtual void HandleLimitReached() = 0;
       virtual ~Observer() {};

};



class OverflowCounter: public Counter{

public:
	OverflowCounter(int intial0 = 0, int upLimit0 = 0);
	void inc(){
	if(intValue >= upLimit){

		intValue = 0;
        notify();

	}else{

		intValue++;
        

		}
	};
	void dec(){
	if(intValue <= 0){

		intValue = upLimit;
        notify();

	}else{

		intValue--;
        

		}
	};
	operator int(){return intValue;};

    void SetObserver(Observer *obss){obs = obss;}

private:
	int intValue;
	int upLimit;
    Observer *obs;
    void notify(){
        obs->HandleLimitReached();
    }

    
};

class CounterUser: public Observer {
    public:
        CounterUser(int limit = 0);
        void IncrementBy(int n);
        void HandleLimitReached(){
            cout << "Limit has been reached";
        }

    private:
        OverflowCounter ofc;
    };

LimitedCounter::LimitedCounter(int value, int limit): intValue(value), upLimit(limit){}

OverflowCounter::OverflowCounter(int value, int limit ): intValue(value), upLimit(limit){}

CounterUser::CounterUser(int limit) {
		ofc.SetObserver(this);
}



void UseCounter(Counter& ctr, int num);

void UseCounter(Counter& ctr, int num){

	if(num <0){

		for (int i=num ; i<0 ; ++i){

			ctr.dec();

		}
	}else if(num > 0){

		for(int i=num ; i>0 ;--i){

			ctr.inc();

		}

	}
}

void CounterUser::IncrementBy(int n){
    for(int i = 0; i < n; ++i){
        ofc.inc();
        cout << ofc ;

    }
}

int main(int argc, char** argv) {
	LimitedCounter lc(0,5);
	OverflowCounter oc(5, 9);

	cout << oc << endl;
	UseCounter(oc, 5);
	cout << oc << endl; // should display zero
	UseCounter(oc, -1);
	cout << oc << endl; // should display 9
	oc.dec();
	cout << oc << endl; // should display 8

	cout << lc << endl;
	lc.inc();
	cout << lc << endl;
	lc.dec();
	cout << lc << endl;
	for(int i = 0; i < 10; ++i) lc.inc();
	cout << lc << endl;
	UseCounter(lc, -9);
	cout << lc << endl;

	return 0;
}
