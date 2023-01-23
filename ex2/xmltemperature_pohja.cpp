
// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");

	string loc,temp;
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}

	cout << "Find what location? \n";
	cin >> loc;
	cout << "Find what temperature? \n";
	cin >> temp;
	// Now page is a string that contains the whole xml page
	
	// Here you need to write something that finds and 
	// extracts location and temperature from the XML
	// data in the string page and stores them in 
	// the strings location and temperature respectively

	location = find_field(page,loc);

	temperature = find_field(page,temp);
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl; 

	return 0;
	
}


string find_field(const string &xml, string tag_name)
{
	// construct start and end tags from from the tag name 
	// add angle brackets to both tags and also slash to end tag
	// then search for tags 
	// if both are found then return the substring between the tags
	
string first = '<' + tag_name + '>';
string end= "</" + tag_name + '>';

const size_t pos_start = xml.find(first);
const size_t pos_end = xml.find(end);


if(pos_start != string::npos)
{

  if(pos_end != string::npos){
	
    return xml.substr(pos_start + first.size(), pos_end - pos_start - end.size()+1);

  }
  
}



	
	return "not found"; // return this if tag is not found
}
