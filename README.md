# Ordered-Linked-List
This assignment was from my CS2420 class "Data Structures And Algorithms" 
I was tasked with creating an ordered linked list based around using the data structure as an organization tool for a list of users/members.
The files "LinkedListTest.cpp" and "MemberDO.h" were given by the professor to allow for me to test the code, and to know what functions I needed to create. All other files were written by me.

MemberDO.cpp
All the functions required for the assignment to store and manipulate a member/user information
Functions:
MemberDO()
  Default constructor to create a member object when no information is given
MemberDO(int k, string ln, char fi, double d)
  Overloaded constructor to create a member object when all information is passed in (First initial, last name, key, and dues)
void setKey(int)
getLastName() const
setLastName(std::string)
getFirstInitial() const
setFirstInitial(char)
getDues() const
getDues(double)
  Get and set functions for a member's first initial, last name, member id (Key) and their dues
Print() const
  to print out all the information for a given member object
ReadFromFile(const char*, OrderedLinkedList<MemberDO>&)
  that simulates reading in information from a file. This actually stores the member objects into the passed in linked list

LinkedList.h
An ordered linked list that sorts data as it is inserted
Functions:
OrderedLinkedList()
  Default constuctor for the linked list. Sets the first and last node pointers to null and length to 0
OrderedLinkedList(const OrderedLinkedList& other)				
  Performs a deep copy on the list and stores it into a new list
~OrderedLinkedList()			
   Destructor that frees all memory used by the linked list
OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other)
   Overloaded assignment operator that performs a deep copy 
insert(const Type&)
    Inserts a new member object into the linked list into the correct sorted location
find(int) const
    Searches through the linked list for a member object matching the given key
get(int) const
    Returns the member object located at the given location
remove(int)
    Removes the node at the given location
clear()
    Empties the list, but does not delete it
size() const
