#include <algorithm> 
#include <iostream>
#include <iterator>  
#include <string>
#include <vector>
#include <iomanip> 
#include <cstdlib>
#include <random>


using namespace std;

class Person {
public:
	Person(const char* name = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
private:
	std::string name;
};
 
class Spy : public Person {
public:
	Spy(const char *names = "nobody",const char *aliass = "noone",int resistances = 0);
	Spy(const Person &pp,const char *aliass, int resistances );
	Spy(const Spy &s);
	virtual void identity()const override;
	virtual void interrogate() override;
	void set_identity(const char *aliass);
private:
	string alias;
	int resistance;

};

Person::Person(const char* name) {
	
	this->name = name;
}

void Person::interrogate(){


}

void Person::identity()const {

	cout << "My name is: " << name << '\n';

}

Spy::Spy(const char *names ,const char *aliass ,int resistances ): Person(names), alias(aliass), resistance(resistances) {}
Spy::Spy(const Person &pp,const char *aliass, int resistances ): Person(pp), alias(aliass), resistance(resistances) {}
Spy::Spy(const Spy &s): Person(s), alias(s.alias), resistance(s.resistance){}

void Spy::identity()const{

	if(resistance > 0){

		cout << "My name is: " << alias << '\n';

	}else if (resistance < 1){
	
		Person::identity();
		cout << "My alias is: " << alias << '\n';

	}
};

void Spy::interrogate(){

	resistance--;

}

void Spy::set_identity(const char *aliass){

	alias = aliass;

}

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}