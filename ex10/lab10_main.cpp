


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

class OverflowCounter: public Counter{

public:
	OverflowCounter(int value = 0, int limit = 0);
	void inc(){
	if(intValue >= upLimit){

		intValue = 0;

	}else{

		intValue++;

		}
	};
	void dec(){
	if(intValue <= 0){

		intValue = upLimit;

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


LimitedCounter::LimitedCounter(int value, int limit): intValue(value), upLimit(limit){}

OverflowCounter::OverflowCounter(int value, int limit): intValue(value), upLimit(limit){}



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
