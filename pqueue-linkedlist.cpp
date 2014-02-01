/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-linkedlist.h"
#include "error.h"



LinkedListPriorityQueue::LinkedListPriorityQueue() {
	head = NULL;
    count = 0;
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	Cell *ptr = head;
    while (ptr) {
        Cell *toDelete = ptr;
        ptr = ptr -> next;
        delete toDelete;
    }
}

int LinkedListPriorityQueue::size() {
	return count;
}

bool LinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void LinkedListPriorityQueue::enqueue(string value) {
	Cell *newCell = new Cell;
    newCell->word = value;
    if (isEmpty()) {
        head = newCell;
        newCell->next = NULL;    
    
    } else {
        Cell *previous = NULL;
        Cell *current = head;
        findInsertionPoint(previous, current, value);
        if(previous == NULL) {
            //Front of List
            newCell->next = current;
            head = newCell;
        } else {
            //Middle of List
            newCell->next = current;
            previous->next = newCell;
        }
        newCell->word = value;
        if (previous) {
            previous->next = newCell;
        }
    }
    count ++;
}

LinkedListPriorityQueue::Cell* LinkedListPriorityQueue::findInsertionPoint(Cell* &previous, Cell* &current, string value) {
    if (current->word > value) {
        return current;
    } else {
        while (current) {
            previous = current;
            current = current->next;
            if (current == NULL)
                return NULL;
            if (current->word > value) {
                return current;
            }
        }
    }
    
}

string LinkedListPriorityQueue::peek() {
    string priorityWord = "";
    if (isEmpty()) {
        error("Error! You are trying to peek at an empty queue.");
    } else {
        priorityWord = head->word;
    }
	return priorityWord;
}

string LinkedListPriorityQueue::dequeueMin() {
    string priorityWord = "";
    if (isEmpty()) {
        error("Error! You are trying to dequeue from an empty queue.");
    } else {
        priorityWord = head->word;
        Cell* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    count --;
	return priorityWord;
}

