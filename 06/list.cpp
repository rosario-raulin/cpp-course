#include "list.hpp"

namespace Collections
{
    SingleLinkedList::SingleLinkedList(const SingleLinkedList& other) {
        size = other.size;
        auto toCopy = other.m_first;
        
        for (int i = 0; i < size; ++i) {
            m_first = new ListEntry(m_first, toCopy->data);
            toCopy = toCopy->next;
        }
    }
    
    SingleLinkedList::SingleLinkedList(const ICollection& other) {
        size = other.getNumElements();
        
        auto it = other.getIterator();
        while (it->current() != nullptr) {
            m_first = new ListEntry(m_first, it->current());
            it->next();
        }
    }
    
	SingleLinkedList::~SingleLinkedList()
	{
		while( m_first )
		{
			ListEntry* next = m_first->next;
			delete m_first;
			m_first = next;
		}
	}


	// Inserts elements at the front of the list.
	void SingleLinkedList::insert( const IElement& newElement )
	{
		++size;
		m_first = new ListEntry( m_first, newElement.clone() );
	}

	IElement* SingleLinkedList::ListIterator::next()
	{
		if( m_current )
		{
			m_current = m_current->next;
			return m_current ? m_current->data : nullptr;
		}
		return nullptr;
	}

	IElement* SingleLinkedList::ListIterator::current() const
	{
		return m_current ? m_current->data : nullptr;
	}

	// Creates a one-time iterator.
	ICollection::IIterator* SingleLinkedList::getIterator() const
	{
		return new ListIterator( m_first );
	}
};