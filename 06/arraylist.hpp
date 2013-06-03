#pragma once

#include "collection.hpp"

#define BUFSIZE 16

namespace Collections
{
	class ArrayList: public ICollection
	{
    private:
        unsigned int reserved;
        IElement** data;
        
	public:
        ArrayList();
        ArrayList(const ArrayList& other);
        ArrayList(const ICollection& other);
        ~ArrayList();
        
        void insert(const IElement& ele) override;
        
		/// \brief Gets an element by index
		/// \param index	Arrayindex of the inquired element. Will check validity only in debug-mode!
		/// \return Inquired element or nullptr
		IElement* get(unsigned int index) const;

		/// \brief Sets an element by index.
		/// \remarks Will delete the old element
		/// \param index	Arrayindex of the array element that will be overwritten. Will check validity only in debug-mode!
		void set(const IElement& newElement, unsigned int index);

		/// \brief Reserves memory for a given number of elements.
		/// \details This method preserves all previous inserted data. It can
		///		be used to resize the array.
		/// \remarks If the list is already bigger, this function will do nothing
		void reserve(unsigned int reservation);
        
        IIterator* getIterator() const override;
        
        class ArrayIterator : public IIterator {
        private:
            unsigned int size;
            unsigned int curr;
            IElement** data;
        public:
            ArrayIterator(IElement** _data, unsigned int _size) : size(_size), curr(0), data(_data) {}
            virtual IElement* next() override;
            virtual IElement* current() const override;
        };
	};
};