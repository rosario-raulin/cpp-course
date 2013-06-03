#pragma once

#include "collection.hpp"

namespace Collections {
	class SingleLinkedList : public ICollection {
	private:
		struct Node {
			IElement* data;
			Node *next;
		};

		Node *head;

		Node* getNext() const {
			Node* ret = head;
			if (ret == nullptr) return nullptr;
			while (ret->next) {
				ret = ret->next;
			}
			return ret;
		}
		
	public:
		SingleLinkedList() : head(nullptr) {}

		SingleLinkedList(const SingleLinkedList& other) {
			size = other.size;
			if (other.head != nullptr) {
				head = new Node;
				head->data = other.head->data;
				head->next = nullptr;

				Node* n = head;
				Node* onext = other.head->next;
				while (onext != nullptr) {
					n->next = new Node;
					n->next->data = onext->data;
					n->next->next = nullptr;

					onext = onext->next;
				}
			}
		}

		~SingleLinkedList() {
			Node* next = head;
			while (next != nullptr) {
				Node* cur = next;
				next = cur->next;
				delete cur->data;
				delete cur;
			}
		}

		void insert(const IElement& element) {
			Node* n = new Node;
			n->data = element.clone();
			n->next = nullptr;

			Node* old = getNext();
			if (old == nullptr) {
				head = n;
			} else {
				old->next = n;
			}
			++size;
		}

		class ListIterator : public IIterator {
		private:
			Node* curr;
		public:
			ListIterator(Node* head) : curr(head) {}

			IElement* next() {
				if (curr != nullptr) {
					curr = curr->next;
				}
				return current();
			}

			IElement* current() const {
				if (curr != nullptr) {
					return curr->data;
				} else {
					return nullptr;
				}
			}
		};

		IIterator *getIterator() const {
			return new ListIterator(head);
		}
	};
}