#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;


class Observer {
public:
	virtual void HandleLimitReached() = 0;
	virtual ~Observer() {};

};

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



class OverflowCounter: public Counter{

public:
	OverflowCounter(int intial0 = 0, int upLimit0 = 0);
	virtual ~OverflowCounter() {};
	void inc(){
	if(intValue < upLimit){

		++intValue;

	}else{

		notify();
		intValue = 0;
        

		}
	};
	void dec(){
	if(intValue > 0){


		--intValue;

	}else{

		
		intValue = upLimit;
		
        

		}
	};
	operator int(){return intValue;};

	void SetObserver(Observer*);

private:
	int intValue;
	int upLimit;
    Observer *obs;
	void notify();
    
};

void OverflowCounter::notify(){

	obs->HandleLimitReached();



}
void OverflowCounter::SetObserver(Observer* ob) {

	obs = ob;
}

class CounterUser: public Observer {
    public:
        CounterUser(int limit = 0);
        void IncrementBy(int n);
        void HandleLimitReached(){
			cout << "Limit has been reached" << endl;
        }

    private:
        OverflowCounter ofc;
    };

LimitedCounter::LimitedCounter(int value, int limit): intValue(value), upLimit(limit){}

OverflowCounter::OverflowCounter(int value, int limit ): intValue(value), upLimit(limit){}

CounterUser::CounterUser(int limit): ofc(0, limit) {
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
        

    }
}

int main() {

	CounterUser cu(5);
	cu.IncrementBy(12);
	CounterUser cu2(9);
	cu2.IncrementBy(9);
	cout << "Just passing time" << endl;
	cu2.IncrementBy(1);

	return 0;



}



