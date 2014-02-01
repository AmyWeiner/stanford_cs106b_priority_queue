/*******************************************************
 * File: pqueue-linkedlist.h
 *
 * A priority queue class backed by a sorted, singly-linked
 * list.
 */
#ifndef PQueue_LinkedList_Included
#define PQueue_LinkedList_Included

#include <string>
using namespace std;

/* A class representing a priority queue backed by a sorted,
 * singly-linked list.
 */
class LinkedListPriorityQueue {
public:
	/* Constructs a new, empty priority queue backed by a sorted linked list. */
	LinkedListPriorityQueue();
	
	/* Cleans up all memory allocated by this priority queue. */
	~LinkedListPriorityQueue();
	
	/* Returns the number of elements in the priority queue. */
	int size();
	
	/* Returns whether or not the priority queue is empty. */
	bool isEmpty();
	
	/* Enqueues a new string into the priority queue. */
	void enqueue(string value);
	
	/* Returns, but does not remove, the lexicographically first string in the
	 * priority queue.
	 */
	string peek();
	
	/* Returns and removes the lexicographically first string in the
	 * priority queue.
	 */
	string dequeueMin();
	
private:
    /* Type: Cell
     * A cell in a linked list.
     */
    struct Cell {
        string word;
        Cell* next;
    };
    
    /* Instance variables */
    Cell *head;
    int count;
    
    /* Function prototype */
	Cell* findInsertionPoint(Cell* &previous, Cell* &current, string value);    //finds insertion point for word being enqueued
};

#endif
