/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"

const int ALLOCATED_LENGTH = 9;

HeapPriorityQueue::HeapPriorityQueue() {
	words = new string[ALLOCATED_LENGTH];
    allocatedLength = ALLOCATED_LENGTH;
    logicalLength = 0;
}

HeapPriorityQueue::~HeapPriorityQueue() {
	delete[] words;
}

int HeapPriorityQueue::size() {
	return logicalLength;
}

bool HeapPriorityQueue::isEmpty() {
	return logicalLength == 0;
}

void HeapPriorityQueue::enqueue(string value) {
	if (size() == allocatedLength -1) {
        grow();
    }
    words[logicalLength + 1] = value;
    bubbleUp();
    logicalLength ++;
}

void HeapPriorityQueue::grow() {
    allocatedLength *= 2 -1;
    string* temp = new string[allocatedLength];
    for (int i = 1; i < logicalLength +1; i ++) {
        temp[i] = words[i];
    }
    delete[] words;
    words = temp;
}

void HeapPriorityQueue::bubbleUp() {
    int childIndex = logicalLength;
    int parentIndex = childIndex / 2;
    string child = words[childIndex];
    string parent = words[parentIndex];
    while (child < parent && parentIndex > 0) {
        swapWords(child,parent);
        childIndex = parentIndex;   
    }
}

void HeapPriorityQueue::swapWords(string child, string parent) {
    string temp = parent;
    parent = child;
    child = temp;
}

string HeapPriorityQueue::peek() {
    string priorityWord = "";
	if (isEmpty()) {
        error("Error! You are trying to peek at an empty queue.");
    } else {
        priorityWord = words[1];
    }	
	return priorityWord;
}

string HeapPriorityQueue::dequeueMin() {
	string priorityWord = "";
    string last;
    if (isEmpty()) {
        error("Error! You are trying to dequeue from an empty queue.");
    } else {
        priorityWord = words[1];
        last = words[logicalLength];
        swapWords(last, priorityWord);
    }
    bubbleDown();
    logicalLength --;
    return last;
}

void HeapPriorityQueue::bubbleDown() {
    int parentIndex = 1;
    int childOneIndex = (2 * parentIndex);
    int childTwoIndex = (2 * parentIndex) +1;
    string parent = words[parentIndex];
    string childOne = words[childOneIndex];
    string childTwo = words[childTwoIndex];
    string smallerChild = getSmallerChild(childOne, childTwo);
    while (parent > smallerChild && parentIndex <=logicalLength) {
        swapWords(smallerChild, parent);
        parentIndex = findIndex(smallerChild);
    }
}

string HeapPriorityQueue::getSmallerChild(string childOne, string childTwo) {
    if (childOne < childTwo) {
        return childOne;
    } else {
        return childTwo;
    }
}

int HeapPriorityQueue::findIndex(string word) {
    int index = 1;
    for (int i = 1; i < logicalLength; i ++) {
        if (words[i] == word) {
            index = i;
        }
    }
    return index;
}










