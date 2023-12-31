﻿/*

This Node is a node in a letter tree (LettersTree.h)

*/

#pragma once
#include "DynamicArray.h"

// the maximum of child nodes, 26 letters
#define MAX_LETTERS 26

class Node {
private:
	DynamicArray<Node*>* letters;	// available children nodes
	char key;						// the letter of the Node, key = 0 means it has no letter
	bool makeSense;					// sense = true if passed-letters, from the biggest father node to it, forms a word that has meaning	

public:
	Node() {
		letters = new DynamicArray<Node*>(MAX_LETTERS);
		key = 0;
		makeSense = false;
	}

	~Node() {
		for (int i = 0; i < MAX_LETTERS; i++) {
			delete letters->getAt(i);
		}
		delete letters;
	}

	// return a pointer (might be null) pointing to a child node
	Node* getLetterAt(int ind) {
		return letters->getAt(ind);
	}

	// set child node at ind
	void setLetterAt(int ind, Node* pointToLetter) {
		letters->setAt(ind, pointToLetter);
	}

	// set the letter of node
	void setKey(char key) {
		this->key = key;
	}

	// sense = true if passed-letters, from the biggest father node to it, forms a word that has meaning
	void setSense(bool sense) {
		this->makeSense = sense;
	}

	char getKey() {
		return this->key;
	}

	bool getSense() {
		return this->makeSense;
	}

};
