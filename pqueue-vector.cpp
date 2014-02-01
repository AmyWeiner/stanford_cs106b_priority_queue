/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include "error.h"


VectorPriorityQueue::VectorPriorityQueue() {
	
}

VectorPriorityQueue::~VectorPriorityQueue() {

}

int VectorPriorityQueue::size() {
	return wordsVector.size();
}

bool VectorPriorityQueue::isEmpty() {
	return (wordsVector.size() == 0);
}


void VectorPriorityQueue::enqueue(string value) {
	wordsVector.add(value);
}

string VectorPriorityQueue::findPriorityWord() {
    string first = wordsVector[0];
    for (int i = 1; i < wordsVector.size(); i ++) {
        string currentWord = wordsVector[i];
        if (currentWord < first) {
            first = currentWord;
        }
    }
	
	return first;
}

string VectorPriorityQueue::peek() {
    if (wordsVector.isEmpty()) {
		error("Error! You are trying to peek at an empty queue.");
	}
    string word =  findPriorityWord();
    return word;
}

int VectorPriorityQueue::findIndex(string word) {
    int index = 0;
    for (int i = 0; i < wordsVector.size(); i ++) {
        if (wordsVector[i] == word) {
            index = i;
        }
    }
    return index;
}

string VectorPriorityQueue::dequeueMin() {
    if (wordsVector.isEmpty()) {
		error("Error! You are trying to remove elements from an empty queue.");
	}
	string word =  findPriorityWord();
    int index = findIndex(word);
    wordsVector.removeAt(index);
    return word;
}

