
#include <iostream>
#include <string>

using namespace std;

namespace List {


	class Node {
	public:
		int data;
		Node* prev, * next;
		Node(int data);
	};

	Node::Node(int data) {
		this->data = data;
		this->prev = this->next = NULL;
	}

	class LinkedList {
		Node* head;
		Node* tail;
	public:
		LinkedList();

		Node* push_front(int data); // Add element in front
		Node* push_back(int data); // Add element in back
		void pop_front(); // Delete element from front
		void pop_back(); // Delete element from back
		Node* getAt(int index); // find element

		// Return element with index
		Node* operator[](int index) {
			return getAt(index);
		}
		// Insert index beetwen two object
		Node* insert(int index, int data);
		// Delete object beetwen two other
		void erase(int index);
		// Show all list
		void show();

		~LinkedList();
	};

	LinkedList::LinkedList() : head{ NULL }, tail{ NULL } {};

	Node* LinkedList::push_front(int data) {
		Node* ptr = new Node(data);
		ptr->next = head;

		if (head != NULL)
			head->prev = ptr;
		if (tail == NULL)
			tail = ptr;
		head = ptr;

		return ptr;
	}

	Node* LinkedList::push_back(int data) {
		Node* ptr = new Node(data);
		ptr->prev = tail;

		if (tail != NULL)
			tail->next = ptr;
		if (head == NULL)
			head = ptr;
		tail = ptr;

		return ptr;
	}

	void LinkedList::pop_back() {
		if (tail == NULL) return;

		Node* ptr = tail->prev;

		if (ptr != NULL)
			ptr->next = NULL;
		else
			head = NULL;


		delete tail;
		tail = ptr;
	}

	void LinkedList::pop_front() {
		if (head == NULL) return;

		Node* ptr = head->next;

		if (ptr != NULL)
			ptr->prev = NULL;
		else
			tail = NULL;


		delete head;
		head = ptr;
	}

	Node* LinkedList::getAt(int index) {

		if (index < 0)
			return NULL;

		Node* ptr = head;
		int n = 0;

		while (n != index) {
			if (ptr == NULL)
				return NULL;
			ptr = ptr->next;
			n++;
		}
		return ptr;
	}

	Node* LinkedList::insert(int index, int data) {
		Node* right = getAt(index);

		if (right == nullptr)
			return NULL;

		Node* left = right->prev;
		if (left == NULL)
			return push_front(data);

		Node* ptr = new Node(data);

		ptr->prev = left;
		ptr->next = right;
		left->next = ptr;
		right->prev = ptr;

		return ptr;
	}

	void LinkedList::erase(int index) {
		Node* ptr = getAt(index);

		if (right == nullptr)
			return;

		if (ptr == NULL)
			return;

		if (ptr->prev == NULL) {
			pop_front();
			return;
		}

		if (ptr->next == NULL) {
			pop_back();
			return;
		}

		Node* left = ptr->prev;
		Node* right = ptr->next;

		left->next = right;
		right->prev = left;

		delete[] ptr;
	}

	void LinkedList::show() {
		if (head) {
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next) {
				cout << ptr->data << " ";
			}
			cout << endl;
		}
	}

	LinkedList::~LinkedList() {
		while (head != NULL)
			pop_front();
	}


}