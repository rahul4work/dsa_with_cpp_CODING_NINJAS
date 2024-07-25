/*
QUEUE USING A SINGLY LINKED LIST
level : moderate

Problem statement
Implement a Queue Data Structure specifically to store integer data using a Singly Linked List.

The data members should be private.

You need to implement the following public functions :

1. Constructor:
It initialises the data members as required.

2. enqueue(data) :
This function should take one argument of type integer. It enqueues the element into the queue
and returns nothing.

3. dequeue() :
It dequeues/removes the element from the front of the queue and in turn, returns the element 
being dequeued or removed. In case the queue is empty, it returns -1.

4. front() :
It returns the element being kept at the front of the queue. In case the queue is empty, 
it returns -1.

5. getSize() :
It returns the size of the queue at any given instance of time.

6. isEmpty() :
It returns a boolean value indicating whether the queue is empty or not.

Operations Performed on the Stack:
Query-1(Denoted by an integer 1): Enqueues an integer data to the queue.

Query-2(Denoted by an integer 2): Dequeues the data kept at the front of the queue and returns 
it to the caller.

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the front of the
queue but doesn't remove it, unlike the dequeue function.

Query-4(Denoted by an integer 4): Returns the current size of the queue.

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the queue is empty or not.


Constraints:
1 <= q <= 10^5
1 <= x <= 5
-2^31 <= data <= 2^31 - 1 and data != -1

Where 'q' is the total number of queries being performed on the queue, 'x' is the range for every 
query and data represents the integer pushed into the queue. 

Time Limit: 1 second


----------------------------------------------------------------------------------------------------
Sample Input 1:
7
1 17
1 23
1 11
2
2
2
2
Sample Output 1:
17
23
11
-1
----------------------------------------------------------------------------------------------------


----------------------------------------------------------------------------------------------------
Sample Input 2:
3
2
1 10
4
Sample Output 2:
-1 
1
----------------------------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
	// Define the data members
	private:
    Node *frontNode;
    Node *rearNode;
    int size;

   public:
    Queue() {
		// Implement the Constructor
		frontNode = nullptr;
        rearNode = nullptr;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
		return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
		return size == 0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
		Node *newNode = new Node(data);
        if (isEmpty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
		if (isEmpty()) {
            return -1;
        }
        int removedData = frontNode->data;
        Node *temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        size--;
        if (frontNode == NULL) {
            rearNode = NULL;
        }
        return removedData;
    }

    int front() {
        // Implement the front() function
		if (isEmpty()) {
            return -1;
        }
        return frontNode->data;
    }

	~Queue() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}



