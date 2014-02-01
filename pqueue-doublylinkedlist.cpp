/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"
#include "simpio.h"
#include <iostream>
#include <string>
#include "console.h"

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = tail = NULL;
    count = 0;
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	Cell *ptr = head;
    while (ptr) {
        Cell *toDelete = ptr;
        ptr = ptr -> next;
        delete toDelete;
    }
}

int DoublyLinkedListPriorityQueue::size() {
	return count;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	return size() == 0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
    Cell* newCell = new Cell;
    newCell->word = value;
    
    newCell->prev = tail;
    newCell->next = NULL;
    
    if (tail == NULL) {
        head = tail = newCell;
    } else {
        tail->next = newCell;
        tail = newCell;
    }
    count ++;
}

string DoublyLinkedListPriorityQueue::peek() {
    Cell* toReturn = head; 
	if (isEmpty()) {
        error("Error! You are trying to peek at an empty queue.");
    } else {
        for (Cell *priorityCell = head; priorityCell != NULL; priorityCell = priorityCell->next) {
            if (priorityCell->word < toReturn->word) {
                toReturn = priorityCell;
            }
        }
    }
    string priorityWord = toReturn->word;
	return priorityWord;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
    Cell* toReturn = head; 
	if (isEmpty()) {
        error("Error! You are trying to dequeue from an empty queue.");
    } else {
        for (Cell *priorityCell = head; priorityCell != NULL; priorityCell = priorityCell->next) {
            if (priorityCell->word < toReturn->word) {
                toReturn = priorityCell;
            }
        }
        if (toReturn == head) {
                head = head->next;
            if (head == NULL) tail = NULL;
        } else if (toReturn == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }else { 
            (toReturn->prev)->next = toReturn->next;
            (toReturn->next)->prev = toReturn->prev;
        }
    }
    string priorityWord = toReturn->word;
    delete toReturn;
    count --;
	return priorityWord;
}

