#include "arraylist.hpp"

namespace Collections {
    ArrayList::ArrayList() : reserved (BUFSIZE), data(new IElement*[BUFSIZE]) {
        size = 0;
    }
    
    ArrayList::~ArrayList() {
        for (int i = 0 ; i < size; ++i) {
            delete data[i];
        }
        delete[] data;
    }
    
    ArrayList::ArrayList(const ArrayList& other) {
        size = other.size;
        reserved = other.reserved;
        data = new IElement*[other.reserved];
        
        for (int i = 0; i < other.size; ++i) {
            data[i] = other.data[i]->clone();
        }
    }
    
    ArrayList::ArrayList(const ICollection& other) {
        size = other.getNumElements();
        reserved = other.getNumElements();
        data = new IElement*[other.getNumElements()];
        
        int i = 0;
        for (auto it = other.getIterator(); it->current() != nullptr; it->next()) {
            data[i++] = it->current()->clone();
        }
    }
    
    void ArrayList::insert(const IElement& newElement) {
        if (size == reserved) {
            reserved *= 2;
            reserve(reserved);
        }
        data[size++] = newElement.clone();
    }
    
    IElement* ArrayList::get(unsigned int index) const {
        return data[index];
    }
    
    void ArrayList::set(const IElement &newElement, unsigned int index) {
        data[index] = newElement.clone();
    }
    
    void ArrayList::reserve(unsigned int reservation) {
        if (reservation > reserved) {
            IElement** newData = new IElement*[reservation];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            reserved = reservation;
            delete [] data;
            data = newData;
        }
    }
    
    IElement* ArrayList::ArrayIterator::current() const {
        if (curr < size) {
            return data[curr];
        } else {
            return nullptr;
        }
    }
    
    IElement* ArrayList::ArrayIterator::next() {
        ++curr;
        return current();
    }
    
    ICollection::IIterator* ArrayList::getIterator() const {
        return new ArrayList::ArrayIterator(data, size);
    }
}