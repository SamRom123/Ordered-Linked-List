#include "MemberDO.h"
#include <iostream>
#include <fstream>

using namespace std;


/*
int key;
std::string lastName;
char firstInit;
double dues;
*/

MemberDO::MemberDO()		//Default constructor for a member
{
	//Stores all defult values for a member
	key = 0;			
	lastName = '\0';
	firstInit = '\0';
	dues = 0;
}

MemberDO::MemberDO(int k, string ln, char fi, double d)		//Constructor for a member with all parameters
{
	//Stores the passed in values
	key = k;		
	lastName = ln;
	firstInit = fi;
	dues = d;
}

int MemberDO::getKey() const		//Returns the key for a given member object
{
return key;
}

void MemberDO::setKey(int k)		//Updates/sets the key for a given memeber object
{
	key = k;
}

string MemberDO::getLastName() const	//Returns the last name for a given memeber object
{
return lastName;
}

void MemberDO::setLastName(string ln)	//Updates/Sets the last name for a given memeber object
{
	lastName = ln;
}

char MemberDO::getFirstInitial() const //Returns the first intitial for a given memeber object
{
return firstInit;
}

void MemberDO::setFirstInitial(char fi) //Updates/sets the first initial for a given memeber object
{
	firstInit = fi;
}

double MemberDO::getDues() const	//Returns the dues for a given memeber object
{
return dues;
}

void MemberDO::setDues(double d)	//Updates/sets the dues for a given memeber object
{
	dues = d;
}

void MemberDO::print() const	//Prints out the information stored within a member object
{
	cout << key << ' ' << lastName << ' ' << firstInit << ' ' << dues << endl;
}

void MemberDO::readFromFile(const char* file, OrderedLinkedList<MemberDO>& ll)	//"reads" in information from a "file" and processes it (Given by professor)
{
	
    MemberDO data;					//Creates a member object for storing the data
	//Stores in all 4 values
    data.key = 6789;
    data.lastName = "Towson";
    data.firstInit = 'J';
    data.dues = 65.25;
    ll.insert(data);				//Calls the insert function to store the member object into the linked list

	//Stores in all 4 values
    data.key = 3456;				
    data.lastName = "Johns";
    data.firstInit = 'K';
    data.dues = 200.00;
    ll.insert(data);				//Calls the insert function to store the member object into the linked list

	//Stores in all 4 values
    data.key = 1123;
    data.lastName = "Stevens";
    data.firstInit = 'M';
    data.dues = 112.35;
    ll.insert(data);				//Calls the insert function to store the member object into the linked list
	
	//Stores in all 4 values
    data.key = 4489;
    data.lastName = "Ellwood";
    data.firstInit = 'B';
    data.dues = 700.25;
    ll.insert(data);				//Calls the insert function to store the member object into the linked list

	//Stores in all 4 values
    data.key = 5555;
    data.lastName = "Pryor";
    data.firstInit = 'R';
    data.dues = 99.99;
    ll.insert(data); 				//Calls the insert function to store the member object into the linked list 

}

