#ifndef HAVE_LINKED_LIST_HPP
#define HAVE_LINKED_LIST_HPP

#include "List.hpp"
#include <exception>

template <class T>
class LinkedList : public List<T> {
private:
	template <class U>
	struct Node {
		U data;
		Node<U>* next;
	};

	int size;
	Node<T>* head;

	Node<T>* getNext() const {
		Node<T>* ret = head;
		for (int i = 0; i < size-1; ++i) {
			ret = ret->next;
		}
		return ret;
	}

public:
	LinkedList() : size(0), head(nullptr) {}
	
	LinkedList(const LinkedList& other) {
		size = other.size;
		if (other.	head != nullptr) {
			head = new Node<T>;
			head->data = other.head.data;
			head->next = nullptr;

			Node<T>* n = head;
			Node<T>* onext = other.head.next;
			while (onext != nullptr) {
				n->next = new Node<T>;
				n->next->data = onext->data;
				n->next->next = nullptr;

				onext = onext->next;
			}
		}
	}

	~LinkedList() {
		Node<T>* next = head;
		while (next != nullptr) {
			Node<T>* cur = next;
			next = cur->next;
			delete cur;
		}
	}

	void add(const T element) {
		Node<T>* n = new Node<T>;
		n->data = element;
		n->next = nullptr;

		Node<T>* old = getNext();
		if (old == nullptr) {
			head = n;
		} else {
			old->next = n;
		}
		++size;
	}

	const T& get() const {
		Node<T>* n = getNext();
		if (n == nullptr) {
			throw std::exception();
		} else {
			return n->data;
		}
	}

	int getSize() const {
		return size;
	}
};

#endif