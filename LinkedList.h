#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <stdexcept>

using std::out_of_range;

//Struct for nodes
template <class Type>
struct Node
{
	Type info;		//Holds the actual data wanting to be stored
	Node *next;		//Points to the next node
};

//Linked list class
template <class Type>
class OrderedLinkedList
{

private:
	Node<Type> *first, *last;	//Creates to node structs to point to the start and end of the linked list
	int length;					//Stores the length of the list

public:
	OrderedLinkedList();															//Default constructor
	OrderedLinkedList(const OrderedLinkedList& other);								//Copies the linked list into a new list
	~OrderedLinkedList();															//Destructor
	
	OrderedLinkedList<Type>& operator=(const OrderedLinkedList<Type>& other);		//Overloaded assignment operator
	
	int insert(const Type&);	//Inserts an item into the ordered linked list
	Type* find(int) const;		//Traverses the list to find the data matching the given key
	Type* get(int) const;		//Grabs the info located at the specified position in the linked list
	int remove(int);			//Removes a node based on the given member key
    void clear();				//Empties the list
    int size() const;			//Returns the size of the list
};


template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList()
{
	first = nullptr;	//Sets the default values for the linked list
	last = nullptr;
	length = 0;
}

template <class Type>
OrderedLinkedList<Type>::OrderedLinkedList(const OrderedLinkedList<Type>& other)

{

	length = other.length;							//Sets the lengths equal to each other
	Node<Type> *temp = new Node<Type>;				//Creates a temporary node for storage
	temp->info = other.first->info;					//Stores the info in the first position of other into the new link list
	temp->next = 0;									//Makes sure that the garbage data in next is removed
	first = temp;									//Sets "this" first to point to the temp node
	last = temp;									//Sets "this" last to point to the temp node
	temp = other.first->next;						//Sets temp to point to the second node in other linked list

	while (temp != nullptr) {						//While the next location temp is pointing to is not null
		Node<Type> *current = new Node<Type>;		//Creates a non pointer node to store the other link list
		last->next = current;						//Tells the tail of our new link list to point to the newly created node
		last = current;								//Moves "this" last to point to the new end of the list
		last->info = temp->info;					//Grabs the information in temp (The other linked list) and stores it
		temp = temp->next;							//Moves temp to point to the next node in the other linked list
	}

	last->next = nullptr;							//Sets the last node's "next" to null
	

}

template <class Type>
OrderedLinkedList<Type>::~OrderedLinkedList()
{
	Node<Type> *temp;					//Creates a node pointer for iteration
	Node<Type> *current;				//Creates a node pointer for deleting

	if (first == nullptr){				//If the link list is already empty, return
		return;
	}

	temp = first->next;					//Points temp to the node after first		
	current = first;					//Points current to the first node in the list

	while (current != 0) {				//Loops until there are no more nodes in the array

		delete current;					//Deletes the current node in the list
		current = temp;					//Sets current equal to the next node in the list
		if (temp == 0) {}				//If temp is null, do nothing
		else { temp = temp->next; }		//Else, move temp along the list
	}
	temp = nullptr;						//Removes dangling pointers
	current = nullptr;					//Removes dangling pointers
	first = nullptr;					//Removes dangling pointers
	last = nullptr;						//Removes dangling pointers
}

template <class Type>
OrderedLinkedList<Type>& OrderedLinkedList<Type>::operator=(const OrderedLinkedList& other)
{
	length = other.length;							//Sets the lengths equal to each other
	Node<Type> *temp = new Node<Type>;				//Creates a temporary node for storage
	temp->info = other.first->info;					//Stores the info in the first position of other into the new link list
	temp->next = 0;									//Makes sure that the garbage data in next is removed
	first = temp;									//Sets "this" first to point to the temp node
	last = temp;									//Sets "this" last to point to the temp node
	temp = other.first->next;						//Sets temp to point to the second node in other linked list

	while (temp != nullptr) {						//While the next location temp is pointing to is not null
		Node<Type> *current = new Node<Type>;		//Creates a pointer node to store the other link list
		last->next = current;						//Tells the tail of our new link list to point to the newly created node
		last = current;								//Moves "this" last to point to the new end of the list
		last->info = temp->info;					//Grabs the information in temp (The other linked list) and stores it
		temp = temp->next;							//Moves temp to point to the next node in the other linked list
	}

	last->next = nullptr;							//Sets the last node's "next" to null

	return *this;
}

template <class Type>
int OrderedLinkedList<Type>::insert(const Type& item)
{
	Node<Type> *newNode = new Node<Type>;
	newNode->info = item;
	//Inserting empty
	if ((first == 0) && (last == 0)) {							//Checks if the linked list is empty
		Node<Type> *temp = new Node<Type>;						//Creates a node for storage

		temp->info = item;										//Stores the passed in object into the node
		first = temp;											//Sets first equal to the node
		last = temp;											//Sets last equal to the node
		length++;												//Increases the length by 1
		last->next = nullptr;									//Sets the last node's "next" to null
		return item.getKey();									//Returns the key of the data
	}
	else {														//Else the link list has information

		Node<Type> *temp = new Node<Type>;						//Creates a node for storage/looping
		
		temp = first;											//Sets temp to the first node in the list

		//Replacing First
		if (item.getKey() < temp->info.getKey()) {				//Checks if the first value of the link list greater than the node
			newNode->next = temp;								//Has newNode point to the first item in the list
			first = newNode;									//Sets first to newNode
			length++;											//Increases the length by 1
			return item.getKey();								//Returns the key
		}

		temp = last;											//Sets temp to the last node in the list

		//Replacing Last
		if (item.getKey() > temp->info.getKey()) {
			last->next = newNode;								//Has the last item in the list point to newNode
			last = newNode;										//Moves last to newNode
			length++;											//Increases the length by 1
			last->next = nullptr;									//Sets the last node's "next" to null
			return item.getKey();								//Returns the key
		}

		temp = first;											//Sets temp to the first node in the list
		
		//Inserting middle
		for (int i = 0; i > -1; i++) {							//Loops through each value of the list
			if (item.getKey() < temp->next->info.getKey()) {	//Checks the key value of the node after temp is less than the item being passed in
			
				newNode->next = temp->next;						//Newnode now points to the node after temp.
				temp->next = newNode;							//The node temp is pointing to, now points to new node
				length++;										//Increases the length by 1
				return temp->next->info.getKey();				//Return the value stored in the new node
			}
			else {
				temp = temp->next;								//moves temp along the list
			}
		}
		return -1;												//If something goes wrong, return -1
	}
}
template <class Type>
Type* OrderedLinkedList<Type>::get(int dest) const
{
	if (dest < 0 || dest >= length) {									//Checks if dest is negative, or greater than the length
		return nullptr;													//Returns nullptr if dest is out of range

	}

	Node<Type> *temp = new Node<Type>;									//Creates a temp node for iteration

	temp = first;														//Points the temp node to the list

	for (int i = 0; i < dest; i++) {									//Moves the temp along the list to the destination
		temp = temp->next;												//Points the temp to the next node
	}

return &temp->info;														//Returns the address of the information stored in temp
}

template <class Type>
Type* OrderedLinkedList<Type>::find(int dest) const
{
	if ((dest < 0)) {													//Checks if dest is less than 0, or larger than the length
		return nullptr;													//Returns nullptr if dest is out of range
	}
	Node<Type> *temp = new Node<Type>;									//Creates a temp node for iteration
	temp = first;														//Points the temp node to the list
	for (int i = 0; i < length; i++) {									//Loops through the list until the end is reached
		if (dest == temp->info.getKey()) {
			return &temp->info;											//Returns the address of the information stored in temp
		}
		else {						
			temp = temp->next;											//Iterates temp to the next node in the list
		}
	}
	return nullptr;
}

template <class Type>
int OrderedLinkedList<Type>::remove(int key)
{
	if (key < 0) {														//Checks to see if key is less than 0
		return -1;														//Returns -1
	}

	Node<Type> *temp;													//Creates a temp node place holding

	//Removing First
	temp = first;														//Points Temp to the first node
	if (key == temp->info.getKey()) {									//Checks if the first node of the list is the object to remove
		first = first->next;											//Moves first to the second node in the list
		delete temp;													//Deletes the first node in the list
		length--;														//Lowers the length by 1
		return key;														//Returns the key
	}

	//Removing Last
	temp = last;														//Sets temp to the last value of the list
	if (key == last->info.getKey()) {									//Checks if the key is equal to the last value of the list
		last = first;													//Moves last to the first item in the list
		for (int i = 0; i > -1; i++) {									//Assigns last to the second to last value of the list
			if (last->next == temp) {									//If node after where last is currently pointing to is the last item in the list, break out of the loop.
				break;
			}
			else {														//If the next item is not equal to temp, move last along the list
				last = last->next;
			}
		}
		delete temp;													//Deletes the last node in the list
		last->next = nullptr;											//Sets the last node's next to point to null
		length--;														//Lowers the length by 1
		return key;
	}
	//Removing middle
	temp = first;														//Points temp to the first node of the list
	Node<Type> *current;												//Creates a node pointer for holding the list location
	for (int i = 0; i < length; i++) {									//Loops through the list until the length, or a value is returned
		if (temp->next == nullptr) {									//If the key is not found, break
			break;
		}
		if (key == temp->next->info.getKey()) {							//Checks if the next node in the list has key value
			current = temp->next;										//gets the location of the node to remove
			temp->next = temp->next->next;								//Redirects the temp node to point to the node after the node with the key value
			delete current;												//Deletes the desired node
			length--;													//Lowers the length by 1
			return key;
		}
		else {															//If the key is not equal, move temp down the list
			temp = temp->next;											//Points temp to the next node in the list
		}
	}
	
	return -1;															//if the key is not found, return -1
}

template <class Type>
void OrderedLinkedList<Type>::clear()
{
	Node<Type> *temp;					//Creates a node pointer for iteration
	Node<Type> *current;				//Creates a node pointer for deleting

	temp = first->next;					//Points temp to the node after first		
	current = first;					//Points current to the first node in the list

	while (current != 0) {				//Loops until there are no more nodes in the array

		delete current;					//Deletes the current node in the list
		current = temp;					//Sets current equal to the next node in the list
		if (temp == 0) {}				//If temp is null, do nothing
		else { temp = temp->next;}		//Else, move temp along the list
	}
	temp = nullptr;						//Removes dangling pointers
	current = nullptr;					//Removes dangling pointers
	first = nullptr;					//Removes dangling pointers
	last = nullptr;						//Removes dangling pointers
	length = 0;							//Sets the length back to 0
}


template <class Type>
int OrderedLinkedList<Type>::size() const
{
return length;							//Return the length of the list
}

#endif
