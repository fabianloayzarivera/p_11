#include "stdafx.h"
#include "06Practica_6.h"

const char* Node::getValue() {
	return value;
}

void Node::setValue(const char* v) {
	value = v;
}

Node* Node::getNextPtr() {
	return next;
}

void Node::setNextPtr(Node *ptr) {
	next = ptr;
}

Node::Node(const char* v) {
	next = nullptr;
	value = v;
}

TList::TList() {
	size = 0;
	index = 0;
}

TList::~TList() {
	Node *actual = first;
	for (int i = 0; i < size; i++) {
		Node *next = actual->getNextPtr();
		delete(actual);
		actual = next;
	}
}

int TList::Size() {
	return size;
} // Retorna el n�mero de elementos.

int TList::Push(const char *psz) {
	Node *n = new Node(psz);
	Node *actual = first;
	if (size > 0) {
		last->setNextPtr(n);
		last = n;
	}
	else {
		first = n;
		last = n;
	}
	size++;
	return size;
}; // A�ade la cadena a la lista.

const char * TList::First() {
	if (size > 0)
		return first->getValue();
	else
		return "empty";
} // retorna el primer elemento de la lista.

const char * TList::Next() {
	Node* actual = first;
	if (index < size) {
		for (int i = 0; i < index; i++) {
			actual = actual->getNextPtr();
		}
		index++;
		return actual->getValue();
	}
	else {
		index = 0;
		return actual->getValue();
	}
} // retorna el siguiente elemento de la lista.

const char * TList::Pop() {
	if (size > 0) {
		const char* value;
		value = first->getValue();
		Node *old = first;
		first = first->getNextPtr();
		delete(old);

		index = 0;
		size--;
		return value;
	}
	else {
		return "empty";
	}

} // Elimina y retorna el primer elemento de la lista.

void TList::Reset() {
	Node *actual = first;
	for (int i = 0; i < size; i++) {
		Node *next = actual->getNextPtr();
		delete(actual);
		actual = next;
	}
	size = 0;
} // Elimina todos los elementos de la lista.

Node* TList::getFirst() {
	return first;
}
Node* TList::getLast() {
	return last;
}