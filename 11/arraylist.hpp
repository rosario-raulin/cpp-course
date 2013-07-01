#ifndef HAVE_ARRAYLIST_HPP
#define HAVE_ARRAYLIST_HPP

#include "collection.hpp"
#include <iostream>

static const int DEFAULT_CAPACITY = 16;

namespace Collections {

	template <typename T>
	class ArrayList : public ICollection<T> {
	public:
		ArrayList() : capacity(DEFAULT_CAPACITY), data(new T[DEFAULT_CAPACITY]) {
			m_numElements = 0;
		}

		ArrayList(const ICollection<T>& other) {
			m_numElements = other.getNumElements();
			capacity = 2*(m_numElements);
			data = new T[capacity];

			int i = 0;
			auto it = other.getIterator();
			while (it->current() != nullptr) {
				data[i] = *it->current();
				it->next();
				++i;
			}
		}

		virtual ~ArrayList() {
			delete[] data;
		}

		void resize(size_t to) {
			T* tmp = data;
			capacity = to;
			data = new T[to];

			for (int i = 0; i < to && i < (m_numElements); ++i) {
				data[i] = tmp[i];
			}
			delete[] tmp;
		}

		virtual void insert(const T& element) {
			if (m_numElements == capacity) {
				resize(2*capacity);
			}
			data[m_numElements] = element;
			++(m_numElements);
		}

		T& operator[](unsigned int index) const {
			return data[index];
		}

		class ArrayIterator : public ICollection<T>::IIterator {
		public:
			ArrayIterator( T* first, int numElements ) : 
				m_array( numElements ? first : nullptr ), m_remaining( numElements )		{}

			virtual T* next() override
			{
				if (m_remaining > 1)
				{
					--m_remaining;
					return ++m_array;
				}
				m_remaining = 0;
				m_array = nullptr;
				return nullptr;
			}

			/// \brief Access the current element without changing the iterator
			///
			virtual T* current() const override
			{
				return m_array;
			}

			virtual ~ArrayIterator() override	{}
		private:
			T* m_array;
			int m_remaining;
		};

		virtual std::shared_ptr<typename ICollection<T>::IIterator> getIterator() const {
			return std::make_shared<ArrayIterator>(data, m_numElements);
		}

	protected:
		using ICollection<T>::m_numElements;

	private:
		size_t capacity;
		T* data;
	};
}

#endif
