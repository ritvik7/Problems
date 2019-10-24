//Linked List
#include <bits/stdc++.h>
using namespace std;

// Linked List Node class containing integers as data
class Node{
    public:
	int data;
	Node* next;
};

// Linked List class containing all the common functions one can perform on a Linked List
class LinkedList{
	public:
	Node* head;
	//Constructor initialises the Head pointer to Null
	LinkedList(){
		head = nullptr;
	}
	public:
	//Inserts ELement at the head
	void insertHead(int data);
	//Deletes node from the head
	void deleteHead();
	//Deletes the first Node whose data matches the key
	void deleteKey(int x);
	//Deletes the node from the desired position
	void deleteNode(int x);
	//Inserts node at a desired position
	void insertNode(int data, int x);
	//Returns the length of the List
	int getLength(Node* head);
	//Prints the List from Head onwards
	void printList();
	//Reverses the nodes of a List 
	void reverseList();
	//Deletes the entire list
	void deleteList();
	//Moves the last node to the head
	void lastToHead();
	//Swaps 2 Nodes 
	void nodeSwap(int x, int y);
	//Finds intersection point of two Lists
	Node* getIntersectPoint(Node* head1, Node* head2);
	//Swaps the nodes of a List consecutively in two's
	void pairwiseSwap();
	//Searches for an element in the List
	bool searchNode(int data);
	//This one is recursive (Duh!)
	bool searchNodeRecursive(int data);
	//Deletes any duplicate nodes from a list sorted in non-decreasing order
	void dedupSorted();
	//Checks if loop is present in List
	bool detectLoop();
	//Returns the count of the loop in the List
	bool detectAndCountLoop();
	//Intersect two lists without
	void intersectLists(Node* head1, Node* head2);
	//Checks if data in List forms a Palindrome
	bool detectPalindrome();
	void dedupUnsorted();
	void quickSort();
};

bool LinkedList::detectPalindrome(){
	stack <int> nodes; 
	Node* temp = head;
	while(back->next){
		nodes.push(back->data);
		back = back->next;
	}
	temp = head;
	while(temp){
		if(temp->data != nodes.top()) return 0;
		nodes.pop();
		temp = temp->next;
	}
	return 1;
}

void LinkedList::intersectLists(Node* head1, Node* head2){
	Node* temp = new Node;
	head = temp;
	while(head1 && head2){
		if(head1->data > head2->data){
			head2 = head2->next;
		}
		else if(head1->data < head2->data){
			head1 = head1->next;
		}
		else{
			temp->data = head1->data;
			temp->next = NULL;
			temp = temp->next;
		}
	}
}

int LinkedList::detectAndCountLoop(){
	Node* temp1 = head;
	Node* temp2 = head;
	int count = 0;
	while(1){
		if(!temp1 || !temp1->next) return 0;
		temp1 = temp1->next;
		temp2 = (temp2->next)->next;
		if(temp2->next == temp1 || (temp2->next)->next == temp1){
			Node* temp3 = temp1;
			while(temp3->next != temp1){
				count++;
			}
			return count;	
		} 
	}
}

bool LinkedList::detectLoop(){
	Node* temp1 = head;
	Node* temp2 = head;
	while(temp1 || temp1->next){
		temp1 = temp1->next;
		temp2 = (temp2->next)->next;
		if(temp2->next == temp1 || (temp->next)->next == temp1) return 1;
	}
	return 0;
}

bool LinkedList::searchNode(int data){
	Node* temp = head;
	while(temp){
		if(temp->data == data) return 1;
		temp = temp->next;
	}
	return 0;
}

bool LinkedList::searchNodeRecursive(int data, Node* head){
	if(head == nullptr) return 0;
	Node* temp = head;
	if(temp->data == data) return 1;
	else return searchNodeRecursive(data, temp->next);
}

void LinkedList::dedupSorted(){
	Node* temp = head->next;
	Node* prev = head;
	while(temp){
		if(prev->data == temp->data){
			prev->next = temp->next;
			delete temp;
			temp = prev->next;
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
}

void LinkedList::pairwiseSwap(){
	Node* node = head->next;
	Node* prev = head;
	Node* temp = new Node;
	if(head->next) head = head->next;
	while(prev && temp){
		temp = node->next;
		node->next = prev;
		prev->next = temp; 
	}
}

Node* LinkedList::getIntersectPoint(Node* head1, Node* head2){
	int l1 = getLength(head1), l2 = getLength(head2);	
	int d = mod(l1-l2);
	if(l1>l2){
		while(d--)
			head1 = head1->next;
	else 
		while(d--)
			head2 = head2->next;
	}
	while(head1 != head2){
		if(!head1 || !head2){
			cout<<"Linked Lists don't intersect\n";
			return head1;
		}
	}
	cout<<"Linked Lists intersect at "<<head1->data<<endl;
}

void LinkedList::lastToHead(){
	if(head == nullptr){
		cout<<"List empty!\n";
		return;
	}
	Node* temp = head;
	while(temp->next)
		temp = temp->next;
	temp->next = head;
	head = temp;
	cout<<"Operation Success!\n";
}

void LinkedList::nodeSwap(int x, int y){
	Node* node1, node2, prev1, prev2;
	Node* temp = head;
	Node* prev = new Node;
	if(getLength()<x || getLength()<y){
		cout<<"Invalid positions\n";
		return;
	}
	for(int i = 1, prev = nullptr; temp; i++, temp = temp->next){
		if(x == i){
			prev1 = prev;
			node1 = temp;
		}
		else if(y == i){
			prev2 = prev;
			node2 = temp;
		}
	}
	prev1->next = node2;
	next_node = node2->next;
	node2->next = node1->next;
	prev2->next = node1;
	node1->next = next_node;
	if(x == 1) head = node1;
	else if(y == 1) head = node2;
}

void LinkedList::insertNode(int data, int x){
	Node* prev, temp = head;
	if(x == 1){
		insertHead(data);
		return;
	}
	prev = head;
	for(int i = 2, temp = temp->next; temp; i++, temp = temp->next, prev = prev->next){
		if(i == x){
			Node* new_node = new Node;
			new_node->data = data;
			new_node->next = temp;
			prev->next = new_node;
			return;
		} 
	}
	cout<<"Position "<<x<<" Invalid\n";
}

void LinkedList::deleteList(){
	while(head)
		deleteHead();
	cout<<"List Deleted\n";
}

void LinkedList::deleteNode(int x){
	Node* prev, temp = head;
	if(x == 1){
		deleteHead();
		return;
	}
	prev = head;
	for(int i = 2, temp = temp->next; temp; i++, temp = temp->next, prev = prev->next){
		if(i == x){
			prev->next = temp->next;
			delete temp;
			return;
		} 
	}
	cout<<"No ELement in position "<<x<<" found\n";
}

void LinkedList::deleteKey(int x){
	Node* prev, temp = head;
	if(temp->data == x){ 
		deleteHead();
		return;
	}
	prev = head;
	for(temp = temp->next; temp; temp = temp->next, prev = prev->next){
		if(temp->data == x){
			prev->next = temp->next;
			delete temp;
			return;
		}
	}
	cout<<"Key not found\n";
}

void LinkedList::insertHead(int data){	
	if(head == nullptr){
		head = new Node;
		head->data = data;
		head->next = nullptr;
	}
	else{
		Node* temp = new Node;
		temp->data = data;
		temp->next = head;
		head = temp;
	}
	cout<<head->data<<" has been inserted\n"; 
	return;   
}

void LinkedList::deleteHead(){
	if(head == nullptr)
		cout<<"Linked List is empty!\n";
	else{
		Node* temp = new Node;
		temp = head->next;
		delete head;
		head = temp; 
		cout<<"Head deleted\n";
	}
	return;   
}

void LinkedList::printList(){
	Node* temp = head;
	for(; temp; temp = temp->next)
		cout<<temp->data<<" ";
	cout<<"\n";
	return;
}

int LinkedList::getLength(Node* head){
	int l = 0; 
	Node* temp = head;
	for(; temp; temp = temp->next)
		l++;
	return l;
}

int main(){
	LinkedList l;
	l.insertHead(1);
	l.insertHead(2);
	l.insertHead(3);
	l.insertHead(4);
	l.insertHead(5);	
	l.printList();
	cout<<"Length:"<<l.getLength(l->head)<<"\n";
	l.deleteHead();
	cout<<"Length:"<<l.getLength(l->head)<<"\n";
	l.deleteHead();
	cout<<"Length:"<<l.getLength(l->head)<<"\n";
	l.deleteHead();
	cout<<"Length:"<<l.getLength(l->head)<<"\n";
	l.printList();
	cout<<"Length:"<<l.getLength(l->head)<<"\n";
    return 0;
}

