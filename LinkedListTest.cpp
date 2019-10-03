#include "LinkedList.h"
#include "MemberDO.h"

#include<iostream>
#include<string>


using namespace std;

int total = 0;
int correct = 0;

//This helps with testing, do not modify.
template<class elemType>
bool checkTest(string testName, elemType whatItShouldBe, elemType whatItIs) {

        total++;
	if (whatItShouldBe == whatItIs) {
		cout << "Passed " << testName << " Output was: " << whatItIs << endl;
                correct++;
		return true;
	}
	else {
		cout << "***Failed test " << testName << " ** " << endl << "   Output was "<< whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
		return false;
	}	
}

bool NULLCheckTest(string testName, void * input) {

        total++;
	if (input == nullptr) {
                correct++;
		cout << "Passed " << testName << " NULL test on find method." << endl;
		return true;
	}
	else {
		cout << "***Failed " << testName << "**" << endl << " Output was not NULL." << endl;
		return false;
	}	
}

int main()                                              
{      
    
    //Constructor empty list
    OrderedLinkedList<MemberDO> memberList;
    checkTest("Test 1", 0, memberList.size());
 
    MemberDO data;
    data.setKey(2555);
    data.setLastName("Smith");
    data.setFirstInitial('J');
    data.setDues(15.15);

    //insert - empty list
    checkTest("Test 2", 2555, memberList.insert(data));
    checkTest("Test 3", 2555, memberList.get(0)->getKey());
    checkTest("Test 4", 15.15, memberList.find(2555)->getDues());
    //insert - first
    MemberDO data1(25, "Rogers", 'A', 17.50);
    memberList.insert(data1);
    checkTest("Test 5", string("Rogers"), memberList.get(0)->getLastName());
    //insert - last
    memberList.insert(MemberDO(3100, "Jackson", 'M', 250.00));
    checkTest("Test 6", 3100, memberList.get(2)->getKey());
    //insert - middle
    memberList.insert(MemberDO(2660, "Franklin", 'F', 20.00));
    checkTest("Test 7", 'F', memberList.get(2)->getFirstInitial());
    //First is still fisrt
    checkTest("Test 8", 17.50, memberList.get(0)->getDues());					//Test 8
    //get out of bounds
    NULLCheckTest("Test 9", memberList.get(4));
    NULLCheckTest("Test 10", memberList.get(-3));
    //Check size
    checkTest("Test 11", 4, memberList.size());
    
    //clear
    memberList.clear();
    checkTest("Test 12", 0, memberList.size());
    NULLCheckTest("Test 13", memberList.get(0));
    //empty find
    NULLCheckTest("Test 14", memberList.find(-3));

	MemberDO::readFromFile("Member.dat", memberList);
	// Key of 1st member on list
	checkTest("Test 15", 1123, (memberList.find(1123))->getKey());
	// Lastname of 2nd member on list
	checkTest("Test 16", string("Johns"), (memberList.find(3456))->getLastName());
	// First initial of 3rd member on list
	checkTest("Test 17", 'B', (memberList.find(4489))->getFirstInitial());
	// Dues of 4th member on list
	checkTest("Test 18", 99.99, (memberList.find(5555))->getDues());
	// Testing proper NULL response from find method
	NULLCheckTest("Test 19", memberList.find(5));	
	//Check size
   	checkTest("Test 20", 5, memberList.size());

	//Make copies
	OrderedLinkedList<MemberDO> copy(memberList);
        OrderedLinkedList<MemberDO> copy2;
        copy2 = memberList;
	
	// remove  - middle
	checkTest("Test 21", 4489, memberList.remove(4489));
	// Key of first member on list
	checkTest("Test 22", 1123, (memberList.get(0))->getKey());
	// Lastname of last member on list
	checkTest("Test 23", string("Towson"), (memberList.get(3))->getLastName());
	
	// remove - first
	memberList.remove(1123);
	// Key of 1st member on list
	checkTest("Test 24", 3456, (memberList.get(0))->getKey());
	// Lastname of 6th member on list
	checkTest("Test 25", string("Towson"), (memberList.find(6789))->getLastName());
	
	// remove - last
	memberList.remove(6789);
	// Dues of last member on list
	checkTest("Test 26", 99.99, (memberList.get(1))->getDues());
	
	//Testing proper return value from remove method
	checkTest("Test 27", -1, memberList.remove(6789));

	//remove all
	memberList.remove(5555);
	memberList.remove(3456);
        
	//Check size
   	checkTest("Test 28", 0, memberList.size());
	//Check size
   	checkTest("Test 29", 5, copy.size());
	//Check size
   	checkTest("Test 30", 5, copy2.size());

	//Check size
   	checkTest("Test 31", 6789, copy.find(6789)->getKey());
	//Check size
   	checkTest("Test 32", 6789, copy2.find(6789)->getKey());

        cout << "Passed " << correct << "/" << total << " tests" << endl;;
        cout << "Points earned: " << float(correct)/total*60 << " out of 60" << endl;

    return 0;                                         
}                                                        

