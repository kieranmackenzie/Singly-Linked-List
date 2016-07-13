/*
 *  Author: Kieran Mackenzie
 *  Implementation of a singly linked list, with methods deleteMin(),add(x),size()
 */

#include <iostream>
#include <time.h> // this is so we can analyze the running time
using namespace std;

//Creating the Node structure
struct node{
public:
	int number;
	node* next;
}*start;

// The linked list operations class
class linkedList {

	public:
	int deleteMin();
	void add(int x);
	int size();
	void displayList();
	node* New_node(int); // creates the node


	linkedList()  // Constructor
	{
		start = NULL; // when we create our node , we have to set the starting pointer to NULL
	}

};

int main(){

	linkedList MyList; // Creating an instance of our class LinkedList, called MyList

	while(true)
	{
		int option;
		cout << endl;
		cout <<"Do you want to add(x), deleteMin(), size(), or print your linked list?" << endl;
		cout <<"1 for add(x), 2 for deleteMin(), and 3 for returning the size, 4 to print list, 5 to quit" << endl;
		cin >> option; //catching the user input

		if(option == 1){
			int value;
			cout << "What value do you want to add?" << endl;
			cin >> value;
			MyList.add(value); //calling the add(x) function for MyList
		}
		else if(option == 2){
			int value;
			cout << "Deleting the minimum value in the linked list" << endl;
			value = MyList.deleteMin(); // deleting the minimum from MyList using the deleteMin() function
			cout << "The minimum was: " << value << endl;
		}
		else if(option == 3){
			int size;
			size = MyList.size();
			cout << "Your list size is: " << size << endl;
		}
		else if(option == 4){
			MyList.displayList();
		}
		else if(option == 5){
			cout << "Program ending" << endl;
			return 0;
		}
		else if(option != 1 || option != 2 || option != 3 || option != 4){
			cout << "Did not enter a proper value, try again" << endl; //catch statement in case of a bad user input
		}
	}
return 0;
}

node* linkedList::New_node(int value)
{

    	node* place = new node; // allocate space for the place
        place->number = value; // the value the user input will be stored in the structure
        place->next = NULL; // since we are making a new node, we can just have the next thing it points to be NULL
        return place;

}

void linkedList::add(int value)
{
	clock_t tStart = clock();
    node *place, *p; //creating instances of structures, p is a placeholder
    place = New_node(value); // place will be the location of new node

    cout << place->number << endl;

    // This next bit makes it a First in Last Out

    p = start; // saving start in p
    start = place;
    start->next = p; // pointing to the next node

    printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

int linkedList::deleteMin()
{
	clock_t tStart = clock();
    node *ptr, *ptrMIN, *holder;
    int min, count, spot, i;
    count = 0;
    spot = 1;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return -1; // arbitrary number
    }
    ptr = start;
    min = ptr->number; // assigning the first element to be minimum
    while (ptr->next != NULL)
    {
    	count++;
        ptr = ptr->next;

        if (ptr->number < min)
        {
        	spot = count; // the spot where our minimum is
        	ptrMIN = ptr; // saving the pointer of where our minimum is
        	min = ptr->number; // saving the minimum number
        }

    }
        holder = start;
        cout << spot << endl;

        for (i = 1;i <= spot;i++) // now that we have the spot where our minimum is held, we can cycle through
        	// our list until we reach our location of the minimum to bridge the two nodes that surround the min together
        {
            ptr = holder;
            holder = holder->next; //this guy is always one ahead of the other
        }
        ptr->next = holder->next; //linking the two surrounding nodes together


    printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return min;

}

void linkedList::displayList()
{
    struct node *list; // creating an instance of struct node
    if (start == NULL) // this checks if the list is empty
    {
        cout << "The List is Empty" << endl;
        return;
    }
    list = start; // starting at the beginning of the list
    cout<<"The list is: "<<endl;
    while (list != NULL) //go through the list till we are at the end
    {
        cout<< list->number <<" -> ";
        list = list->next;
    }
    cout<<"NULL"<<endl; // this is always the final thing the last element would point to
}

int linkedList::size(){
	struct node *list; // initialization of the node structure
	int count; // our counter
    list = start; // starting at the beginning
	count = 0;
    while (list != NULL)  // till we reach the end
    {
        list = list->next; // next node
        count++;
    }
    return count; //return list size
}

